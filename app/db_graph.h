#pragma once

#include "db_columns.h"
#include "db_table.h"

#include <QChart>
#include <QChartView>
#include <QDateTimeAxis>
#include <QLineSeries>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QValueAxis>
#include <QWidget>

#include <map>


class DBGraph : public QWidget {
	Q_OBJECT

using Tables = std::map<std::string, std::pair<DBColumns*, QSqlQueryModel*>>;

public:
	DBGraph (
		QSqlDatabase& db,
		std::string title="",
		QWidget* parent=nullptr,
		Qt::WindowFlags f=Qt::WindowFlags());

	// add a table to be able to get lines from.
	void add_table (DBColumns* columns);

	// remove a table.
	void remove_table (std::string table_name);

	// refresh the lines in the chart.
	void refresh ();

	// getters
	std::string get_title ();

	Tables& get_tables ();

	// setters
	void set_title (std::string title);

private:
	// update whether the column `column_name` from the table with checkable columns
	// `columns` should have its line drawn.
	void update_lines (DBColumns* columns, std::string column_name);

	// get a line in the chart from its name.
	// note: to get a properly formatted line name to put into this method, used
	// DBGraph::line_name.
	QtCharts::QLineSeries* get_line (std::string name) const;

	// regenerate the axes of the chart.
	void recreate_axes ();

	// get the name of a line in the chart.
	static std::string line_name (std::string table_name, std::string column_name);

	// get the database query used to retrieve the data for drawing lines.
	static std::string query_string (std::string table, std::string sort_by="");

	static const int MARGINS = 0;

	QSqlDatabase& db;

	std::string title;

	Tables tables;

	/* TODO #speed: implement caching of previously shown lines and their data */
	QtCharts::QChart* chart;
	QtCharts::QChartView* view;
	QtCharts::QDateTimeAxis* x_axis;
	QtCharts::QValueAxis* y_axis;
};
