#include "mainwindow.h"

#include <QSqlQueryModel>
#include <QHBoxLayout>
using namespace QtCharts;


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
                       , frames_columns(new QListWidget(this))
                       , gps_columns(new QListWidget(this))
                       , imu_columns(new QListWidget(this))
                       , health_columns(new QListWidget(this))
                       , img_columns(new QListWidget(this))
                       , config_columns(new QListWidget(this))
                       , columns_tabs(new QTabWidget(this))
                       , series(new QLineSeries(this))
                       , chart(new QChart())
                       , chart_view(new QChartView(this))
                       , graph_tabs(new QTabWidget(this))
                       , graphing_widget(new QWidget(this))
                       , mode_tabs(new QTabWidget(this)) {
	resize(1000, 600);

	setUpTables();
	setUpColumns();
	setUpGraphs();

	QHBoxLayout* layout = new QHBoxLayout(graphing_widget);
	graphing_widget->setLayout(layout);
	layout->addWidget(columns_tabs);
	layout->addWidget(graph_tabs);
	layout->setContentsMargins(tab_margins, tab_margins, tab_margins, tab_margins);
	columns_tabs->setMinimumWidth(columns_tabs->count() * 58); // kind of arbitrary
	columns_tabs->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	graph_tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	mode_tabs->addTab(graphing_widget, "Graphing");
	mode_tabs->addTab(tables_widget, "Tables");
	setCentralWidget(mode_tabs);
}

void MainWindow::setUpTables () {
	tables_tabs->addTab(&frames_table, "Frames");
	tables_tabs->addTab(&gps_table, "GPS");
	tables_tabs->addTab(&imu_table, "IMU");
	tables_tabs->addTab(&health_table, "Health");
	tables_tabs->addTab(&img_table, "IMG");
	tables_tabs->addTab(&config_table, "Config");

	tables_widget->setLayout(new QHBoxLayout(tables_widget));
	tables_widget->layout()->addWidget(tables_tabs);
	tables_widget->layout()->setContentsMargins(
		tab_margins, tab_margins, tab_margins, tab_margins);
}

void MainWindow::setUpColumns () {
	setUpColumns(frames_table.get_model(), frames_columns);
	setUpColumns(gps_table.get_model(), gps_columns);
	setUpColumns(imu_table.get_model(), imu_columns);
	setUpColumns(health_table.get_model(), health_columns);
	setUpColumns(img_table.get_model(), img_columns);
	setUpColumns(config_table.get_model(), config_columns);

	columns_tabs->addTab(frames_columns, "Frames");
	columns_tabs->addTab(gps_columns, "GPS");
	columns_tabs->addTab(imu_columns, "IMU");
	columns_tabs->addTab(health_columns, "Health");
	columns_tabs->addTab(img_columns, "IMG");
	columns_tabs->addTab(config_columns, "Config");
}

void MainWindow::setUpColumns (QSqlQueryModel* model, QListWidget* widget) {
	if (model == nullptr || widget == nullptr)
		return;

	for (int i = 0; i < model->columnCount(); i++) {
		widget->addItem(model->headerData(i, Qt::Horizontal).toString());
		auto item = widget->item(i);
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		item->setCheckState(Qt::Unchecked);
	}
}

void MainWindow::setUpGraphs () {
	series->setName("example");
	series->append(0, 6);
	series->append(2, 4);
	series->append(3, 8);
	series->append(7, 4);
	series->append(10, 5);

	chart->addSeries(series);
	chart->createDefaultAxes();
	chart->setTitle("Simple line chart example");

	chart_view->setChart(chart);
	chart_view->setRenderHint(QPainter::Antialiasing);

	graph_tabs->addTab(chart_view, "Graph");
}

void MainWindow::refresh (const Packet& p) {
	/* TODO #speed: this (I think) is making stuff lag -- might have to explicitly make
	 * this non-blocking? */
	frames_table.refresh(p);
	gps_table.refresh(p);
	imu_table.refresh(p);
	health_table.refresh(p);
	img_table.refresh(p);
	config_table.refresh(p);
}
