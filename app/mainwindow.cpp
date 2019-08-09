#include "mainwindow.h"

#include <QSqlQueryModel>
#include <QHBoxLayout>


MainWindow::MainWindow (QSqlDatabase& db, QWidget* parent, Qt::WindowFlags flags)
                       : QMainWindow(parent, flags), db(db)
                       , frames_table(db, "frames", this)
                       , gps_table(db, "gps", this)
                       , imu_table(db, "imu", this)
                       , health_table(db, "health", this)
                       , img_table(db, "img", this)
                       , config_table(db, "config", this)
                       , tables_tabs(new QTabWidget(this))
                       , tables_widget(new QWidget(this))
                       , tables_dock(new QDockWidget(this))
                       , frames_columns(
                           new DBColumns("frames", *frames_table.get_model(), this))
                       , gps_columns(
                           new DBColumns("gps", *gps_table.get_model(), this))
                       , imu_columns(
                           new DBColumns("imu", *imu_table.get_model(), this))
                       , health_columns(
                           new DBColumns("health", *health_table.get_model(), this))
                       , img_columns(
                           new DBColumns("img", *img_table.get_model(), this))
                       , config_columns(
                           new DBColumns("config", *config_table.get_model(), this))
                       , frames_column_list(new QListView(this))
                       , gps_column_list(new QListView(this))
                       , imu_column_list(new QListView(this))
                       , health_column_list(new QListView(this))
                       , img_column_list(new QListView(this))
                       , config_column_list(new QListView(this))
                       , columns_tabs(new QTabWidget(this))
                       , graph(new DBGraph(db, this))
                       , graph_tabs(new QTabWidget(this))
                       , graphing_split(new QSplitter(this))
                       , graphing_widget(new QWidget(this))
                       , graphing_dock(new QDockWidget(this)) {
	// set the default window size
	int window_width = 1000;
	int window_height = 600;
	resize(window_width, window_height);

	// create constituent widgets
	setUpTables();
	setUpColumns();
	setUpGraphs();

	// set up the default size of the graphing columns
	graphing_split->addWidget(columns_tabs);
	graphing_split->addWidget(graph_tabs);
	int columns_size = columns_tabs->count() * 57;
	int graph_size = window_width - columns_size;
	graphing_split->setSizes({ columns_size, graph_size });

	// add some margins to the graphing tab
	QHBoxLayout* layout = new QHBoxLayout(graphing_widget);
	graphing_widget->setLayout(layout);
	layout->addWidget(graphing_split);
	layout->setContentsMargins(tab_margins, tab_margins, tab_margins, tab_margins);

	// add the main tabs to the window
	tables_dock->setWidget(tables_widget);
	tables_dock->setWindowTitle("Tables");
	graphing_dock->setWidget(graphing_widget);
	graphing_dock->setWindowTitle("Graphs");
	addDockWidget(Qt::BottomDockWidgetArea, tables_dock);
	addDockWidget(Qt::BottomDockWidgetArea, graphing_dock);
	tabifyDockWidget(tables_dock, graphing_dock);
}

void MainWindow::setUpTables () {
	// add table tabs
	tables_tabs->addTab(&frames_table, "Frames");
	tables_tabs->addTab(&gps_table, "GPS");
	tables_tabs->addTab(&imu_table, "IMU");
	tables_tabs->addTab(&health_table, "Health");
	tables_tabs->addTab(&img_table, "IMG");
	tables_tabs->addTab(&config_table, "Config");

	// add some margins
	tables_widget->setLayout(new QHBoxLayout(tables_widget));
	tables_widget->layout()->addWidget(tables_tabs);
	tables_widget->layout()->setContentsMargins(
		tab_margins, tab_margins, tab_margins, tab_margins);
}

void MainWindow::setUpColumns () {
	// link list views to corresonding column models
	frames_column_list->setModel(frames_columns);
	gps_column_list->setModel(gps_columns);
	imu_column_list->setModel(imu_columns);
	health_column_list->setModel(health_columns);
	img_column_list->setModel(img_columns);
	config_column_list->setModel(config_columns);

	columns_tabs->addTab(frames_column_list, "Frames");
	columns_tabs->addTab(gps_column_list, "GPS");
	columns_tabs->addTab(imu_column_list, "IMU");
	columns_tabs->addTab(health_column_list, "Health");
	columns_tabs->addTab(img_column_list, "IMG");
	columns_tabs->addTab(config_column_list, "Config");
}

void MainWindow::setUpGraphs () {
	graph->add_table("gps", gps_columns);
	graph->add_table("imu", imu_columns);
	graph->add_table("health", health_columns);
	graph->add_table("img", img_columns);
	graph->add_table("config", config_columns);

	graph_tabs->addTab(graph, "Graph");
}

void MainWindow::refresh (const Packet& p) {
	Q_UNUSED(p);
	/* TODO #speed: this (I think) is making stuff lag -- might have to explicitly make
	 * this non-blocking? */
	frames_table.refresh();
	gps_table.refresh();
	imu_table.refresh();
	health_table.refresh();
	img_table.refresh();
	config_table.refresh();

	graph->refresh();
}
