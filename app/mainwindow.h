#pragma once

#include "packet.h"
#include "db_columns.h"
#include "db_graph.h"
#include "db_table.h"

#include <QDockWidget>
#include <QListView>
#include <QListWidget>
#include <QMainWindow>
#include <QSplitter>
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
	void setUpGraphs ();

	static const int tab_margins = 5;

	QSqlDatabase& db;

	// tables at the bottom
	DBTable frames_table;
	DBTable gps_table;
	DBTable imu_table;
	DBTable health_table;
	DBTable img_table;
	DBTable config_table;

	QTabWidget* tables_tabs;
	QWidget* tables_widget;
	QDockWidget* tables_dock;

	// checkable list of columns on the side
	DBColumns* frames_columns;
	DBColumns* gps_columns;
	DBColumns* imu_columns;
	DBColumns* health_columns;
	DBColumns* img_columns;
	DBColumns* config_columns;

	QListView* frames_column_list;
	QListView* gps_column_list;
	QListView* imu_column_list;
	QListView* health_column_list;
	QListView* img_column_list;
	QListView* config_column_list;

	QTabWidget* columns_tabs;

	// customisable graph(s) in the centre
	DBGraph* graph;
	QTabWidget* graph_tabs;

	QSplitter* graphing_split;
	QWidget* graphing_widget;
	QDockWidget* graphing_dock;
};
