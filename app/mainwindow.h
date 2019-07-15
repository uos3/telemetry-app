#pragma once

#include "packet.h"
#include "db_table.h"

#include <QChart>
#include <QChartView>
#include <QDockWidget>
#include <QLineSeries>
#include <QListWidget>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QTabWidget>

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(
		QSqlDatabase& db,
		QWidget *parent = nullptr,
		Qt::WindowFlags flags = Qt::WindowFlags());

public slots:
	void refresh (const Packet& p);

private:
	void setUpTables ();
	void setUpColumns ();
	void setUpColumns (QSqlQueryModel* model, QListWidget* widget);
	void setUpGraphs ();

	QSqlDatabase& db;

	// tables at the bottom
	DBTable frames_table;
	DBTable gps_table;
	DBTable imu_table;
	DBTable health_table;
	DBTable img_table;
	DBTable config_table;

	QTabWidget* tables_tabs;
	QDockWidget* tables_dock;

	// checkable list of columns on the side
	QListWidget* frames_columns;
	QListWidget* gps_columns;
	QListWidget* imu_columns;
	QListWidget* health_columns;
	QListWidget* img_columns;
	QListWidget* config_columns;

	QTabWidget* columns_tabs;

	// customisable graph(s) in the centre
	QtCharts::QLineSeries* series;
	QtCharts::QChart* chart;
	QtCharts::QChartView* chart_view;
	QTabWidget* graph_tabs;

	QWidget* graphing_widget;

	// tab between tables and graphs
	QTabWidget* mode_tabs;
};
