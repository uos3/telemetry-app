#include "mainwindow.h"

#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>


MainWindow::MainWindow (QSqlDatabase& db,
                        Uploader& uploader,
                        QWidget* parent,
                        Qt::WindowFlags flags)
                       : QMainWindow(parent, flags), db(db), uploader(uploader)
                       , frames_table(db, "frames", this)
                       , gps_table(db, GPS_TABLE_NAME, this)
                       , imu_table(db, IMU_TABLE_NAME, this)
                       , health_table(db, HEALTH_TABLE_NAME, this)
                       , img_table(db, IMG_TABLE_NAME, this)
                       , config_table(db, CONFIG_TABLE_NAME, this)
                       , tables_tabs(new QTabWidget(this))
                       , tables_widget(new QWidget(this))
                       , tables_dock(new QDockWidget(this))
                       , gps_column_list(new QListView(this))
                       , imu_column_list(new QListView(this))
                       , health_column_list(new QListView(this))
                       , img_column_list(new QListView(this))
                       , config_column_list(new QListView(this))
                       , columns_tabs(new QTabWidget(this))
                       , graph_tabs(new QTabWidget(this))
                       , graphing_split(new QSplitter(this))
                       , graphing_widget(new QWidget(this))
                       , graphing_dock(new QDockWidget(this))
                       , toolbar(new QToolBar(this))
                       , refresh_action(nullptr)
                       , upload_action(nullptr)
                       , auto_refresh_action(nullptr)
                       , uploader_settings(new UploaderSettings(uploader, this))
                       , notifier(nullptr)
                       , auto_refresh(false) {
	// set the default window size.
	int window_width = 1000;
	int window_height = 600;
	resize(window_width, window_height);

	// create constituent widgets.
	set_up_tables();
	set_up_columns();
	set_up_graph_tabs();
	set_up_toolbar();

	// set up the default size of the graphing columns.
	graphing_split->addWidget(columns_tabs);
	graphing_split->addWidget(graph_tabs);
	int columns_size = columns_tabs->count() * 57;
	int graph_size = window_width - columns_size;
	graphing_split->setSizes({ columns_size, graph_size });

	// add some margins to the graphing tab.
	QHBoxLayout* layout = new QHBoxLayout(graphing_widget);
	graphing_widget->setLayout(layout);
	layout->addWidget(graphing_split);
	layout->setContentsMargins(TAB_MARGINS, TAB_MARGINS, TAB_MARGINS, TAB_MARGINS);

	// add the main tabs to the window.
	tables_dock->setWidget(tables_widget);
	tables_dock->setWindowTitle("Tables");
	graphing_dock->setWidget(graphing_widget);
	graphing_dock->setWindowTitle("Graphs");
	addDockWidget(Qt::BottomDockWidgetArea, tables_dock);
	addDockWidget(Qt::BottomDockWidgetArea, graphing_dock);
	tabifyDockWidget(tables_dock, graphing_dock);

	// add the toolbar at the top.
	addToolBar(Qt::TopToolBarArea, toolbar);
}

void MainWindow::notify_from (Output* output) {
	this->notifier = output;
}

void MainWindow::set_auto_refresh (bool auto_refresh) {
	if (notifier == nullptr)
		return;

	if (auto_refresh) {
		connect(notifier, &Output::packet_output, this, &MainWindow::refresh,
		        Qt::UniqueConnection);
	} else {
		disconnect(notifier, &Output::packet_output, this, &MainWindow::refresh);
	}

	auto_refresh_action->setChecked(auto_refresh);
}

void MainWindow::refresh () {
	/* TODO #speed: this (I think) is making stuff lag -- might have to explicitly make
	 * this non-blocking? */
	frames_table.refresh();
	gps_table.refresh();
	imu_table.refresh();
	health_table.refresh();
	img_table.refresh();
	config_table.refresh();

	dynamic_cast<DBGraph*>(graph_tabs->currentWidget())->refresh();
}

void MainWindow::configure_uploader () {
	if (uploader_settings == nullptr) return;

	uploader_settings->show();
	uploader_settings->raise();
	uploader_settings->activateWindow();
}

void MainWindow::upload (const std::vector<int>& frames) {
	// TODO #finish: invoke the uploader -- will prob want an extra db table with
	//               (foreign) 'frame id' + 'is uploaded' to know what to upload (in
	//               lieu of extra user control).
	Q_UNUSED(frames);
	qDebug("finish me.");
}

void MainWindow::set_up_tables () {
	// add table tabs.
	tables_tabs->addTab(&frames_table, QString::fromStdString(FRAMES_TITLE));
	tables_tabs->addTab(&gps_table, QString::fromStdString(GPS_TITLE));
	tables_tabs->addTab(&imu_table, QString::fromStdString(IMU_TITLE));
	tables_tabs->addTab(&health_table, QString::fromStdString(HEALTH_TITLE));
	tables_tabs->addTab(&img_table, QString::fromStdString(IMG_TITLE));
	tables_tabs->addTab(&config_table, QString::fromStdString(CONFIG_TITLE));

	// add some margins.
	tables_widget->setLayout(new QHBoxLayout(tables_widget));
	tables_widget->layout()->addWidget(tables_tabs);
	tables_widget->layout()->setContentsMargins(
		TAB_MARGINS, TAB_MARGINS, TAB_MARGINS, TAB_MARGINS);
}

void MainWindow::set_up_columns () {
	// add a tab in the columns view for each table that you might want to graph.
	columns_tabs->addTab(gps_column_list, QString::fromStdString(GPS_TITLE));
	columns_tabs->addTab(imu_column_list, QString::fromStdString(IMU_TITLE));
	columns_tabs->addTab(health_column_list, QString::fromStdString(HEALTH_TITLE));
	columns_tabs->addTab(img_column_list, QString::fromStdString(IMG_TITLE));
	columns_tabs->addTab(config_column_list, QString::fromStdString(CONFIG_TITLE));
}

void MainWindow::set_up_graph_tabs () {
	// add 'x' close buttons to tabs.
	graph_tabs->setTabsClosable(true);

	// add an 'add tab' tab, and hide its close button.
	QLabel* add_tab_label = new QLabel(
		"To add a graph, click the '+' button above.", this);
	add_tab_label->setAlignment(Qt::AlignCenter);
	graph_tabs->insertTab(0, add_tab_label, "+");
	graph_tabs->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);

	// add a starting graph, and focus on it.
	add_graph();
	graph_tabs->setCurrentIndex(0);
	set_active_graph(graphs[0]);

	// connect signal to change tab.
	connect(
		graph_tabs, &QTabWidget::currentChanged,
		this, [this](int index){
			if (index == graph_tabs->count() - 1) {
				graph_tabs->setCurrentIndex(index - 1);
				return;
			}

			auto graph = dynamic_cast<DBGraph*>(graph_tabs->widget(index));
			auto it = std::find(graphs.begin(), graphs.end(), graph);

			if (it != graphs.end())
				set_active_graph(graph);
		});

	// connect signal to add tabs.
	connect(
		graph_tabs, &QTabWidget::tabBarClicked,
		this, [this](int index){
			if (index != graph_tabs->count() - 1)
				return;

			add_graph();
			graph_tabs->setCurrentIndex(graph_tabs->count() - 2);
		});

	// connect signal to remove tabs.
	connect(
		graph_tabs, &QTabWidget::tabCloseRequested,
		this, [this](int index){
			if (index == graph_tabs->count() - 1)
				return;

			DBGraph* to_remove = dynamic_cast<DBGraph*>(graph_tabs->widget(index));

			graph_tabs->removeTab(index);

			auto remove_it = std::find(graphs.begin(), graphs.end(), to_remove);
			graphs.erase(remove_it);
			delete to_remove;

		});

	// connect signal to rename tabs.
	connect(
		graph_tabs, &QTabWidget::tabBarDoubleClicked,
		this, [this](int index){
			if (index == graph_tabs->count() - 1)
				return;

			bool ok = true;
			QString new_name = QInputDialog::getText(
				this, "Change Graph Name", "Insert new graph name:", QLineEdit::Normal,
				graph_tabs->tabText(index), &ok);

			if (!ok)
				return;

			graph_tabs->setTabText(index, new_name);
			DBGraph* graph = dynamic_cast<DBGraph*>(graph_tabs->widget(index));
			graph->set_title(new_name.toStdString());
		});
}

void MainWindow::set_up_toolbar () {
	// left-aligned actions.
	refresh_action = toolbar->addAction("Refresh");
	upload_action = toolbar->addAction("Upload");

	// empty spacer in the middle.
	auto spacer = new QWidget(toolbar);
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	toolbar->addWidget(spacer);

	// right-aligned actions.
	auto_refresh_action = toolbar->addAction("Auto-refresh");
	upload_config_action = toolbar->addAction("Configure uploads");

	// connect up signals, and other initialisation.
	connect(refresh_action, &QAction::triggered, this, &MainWindow::refresh);

	auto_refresh_action->setCheckable(true);
	connect(auto_refresh_action, &QAction::toggled, this, &MainWindow::set_auto_refresh);

	connect(upload_config_action, &QAction::triggered,
	        this, &MainWindow::configure_uploader);

	set_auto_refresh(auto_refresh);
}

DBGraph* MainWindow::add_graph () {
	// create a new graph.
	std::string name = "Graph " + std::to_string(graphs.size() + 1);
	DBGraph* graph = new DBGraph(db, name, this);

	// give it DBColumns models, for each table we want checkable boxes for.
	graph->add_table(new DBColumns(GPS_TABLE_NAME, *gps_table.get_model(), this));
	graph->add_table(new DBColumns(IMU_TABLE_NAME, *imu_table.get_model(), this));
	graph->add_table(new DBColumns(HEALTH_TABLE_NAME, *health_table.get_model(), this));
	graph->add_table(new DBColumns(IMG_TABLE_NAME, *img_table.get_model(), this));
	graph->add_table(new DBColumns(CONFIG_TABLE_NAME, *config_table.get_model(), this));

	graphs.push_back(graph);
	graph_tabs->insertTab(graph_tabs->count() - 1, graph, QString::fromStdString(name));

	return graph;
}

void MainWindow::set_active_graph (DBGraph* graph) {
	// link list views to corresonding column models, for the active graph.
	gps_column_list->setModel(graph->get_tables().at(GPS_TABLE_NAME).first);
	imu_column_list->setModel(graph->get_tables().at(IMU_TABLE_NAME).first);
	health_column_list->setModel(graph->get_tables().at(HEALTH_TABLE_NAME).first);
	img_column_list->setModel(graph->get_tables().at(IMG_TABLE_NAME).first);
	config_column_list->setModel(graph->get_tables().at(CONFIG_TABLE_NAME).first);

	/* TODO #correctness: is this always wanted (even if auto-refresh is off)? */
	graph->refresh();
}
