#include "db_graph.h"

#include <QDebug>

#include <QDateTime>
#include <QList>
#include <QPointF>
#include <QSqlField>
#include <QSqlRecord>
#include <QVBoxLayout>
using namespace QtCharts;


DBGraph::DBGraph (QSqlDatabase& db, QWidget* parent, Qt::WindowFlags f)
                 : QWidget(parent, f)
                 , db(db)
                 , chart(new QChart())
                 , view(new QChartView(this))
                 , x_axis (nullptr)
                 , y_axis (nullptr) {
	chart->setTitle("Simple DBGraph example");

	recreateAxes();

	view->setChart(chart);
	view->setRenderHint(QPainter::Antialiasing);

	setLayout(new QVBoxLayout(this));
	layout()->addWidget(view);
	layout()->setContentsMargins(margins, margins, margins, margins);
}

void DBGraph::add_table (std::string table_name, DBColumns* columns) {
	auto query_model = new QSqlQueryModel(this);
	std::string query_str = DBGraph::query_string(table_name, "timestamp");
	query_model->setQuery(QSqlQuery(QString::fromStdString(query_str), db));

	tables[table_name] = std::make_pair(columns, query_model);

	connect(
		columns, &DBColumns::column_toggled,
		this, [this](std::string column_name){
			update_lines(dynamic_cast<DBColumns*>(sender()), column_name);
		});
}

void DBGraph::remove_table (std::string table_name) {
	auto it = tables.find(table_name);
	if (it == tables.end())
		return;
	DBColumns* columns = it->second.first;

	disconnect(columns, nullptr, this, nullptr);

	tables.erase(table_name);
}

void DBGraph::refresh () {
	/* TODO #speed: use frame_id to just append new data, instead of throwing all the
	 *              graphs away and starting again each time. might also want to provide
	 *              a force-regen button in this case, to actually regenerate everything
	 *              (just in case). */
	for (auto l : chart->series()) {
		(dynamic_cast<QLineSeries*>(l))->clear();
	}

	for (auto& table : tables) {
		// go through each table. since our graphs are temporal, ignore tables that
		// don't have a 'timestamp' column.
		std::string table_name = table.first;
		DBColumns* columns = table.second.first;
		QSqlQueryModel* model = table.second.second;

		model->setQuery(model->query());
		model->query().exec();

		int timestamp_idx = model->query().record().indexOf("timestamp");
		if (timestamp_idx == -1)
			continue;

		for (int col=0; col < model->columnCount(); col++) {
			// see which columns in the table we have a line for.
			std::string column_name = columns->get_column_names()[col];
			std::string line_name = DBGraph::line_name(table_name, column_name);
			QLineSeries* line = get_line(line_name);

			if (line == nullptr)
				continue;

			bool can_graph = true;
			QList<QPointF> points;
			for (int row=0; row < model->rowCount(); row++) {
				// create proper datapoints for the line, breaking if the type of data
				// isn't right for a line chart.
				qreal val = model->data(model->index(row, col)).toReal(&can_graph);
				if (!can_graph)
					break;

				QDateTime timestamp = model->data(
					model->index(row, timestamp_idx)).toDateTime();
				if (!timestamp.isValid()) {
					can_graph = false;
					break;
				}

				points.append(QPointF(timestamp.toMSecsSinceEpoch(), val));
			}

			// if applicable, set the points we just created as the line's data. note:
			// if we don't remove/re-add the series, the line doesn't draw. also, we
			// append all our points at once to possibly save on redraws.
			if (!can_graph)
				continue;

			line->append(points);

			chart->removeSeries(line);

			chart->addSeries(line);
		}
	}

	recreateAxes();
}

void DBGraph::update_lines (DBColumns* columns, std::string column_name) {
	if (columns == nullptr)
		return;

	std::string line_name = DBGraph::line_name(columns->get_name(), column_name);

	bool now_checked = columns->is_checked(column_name);

	auto affected_line = get_line(line_name);

	if (now_checked && affected_line == nullptr) {
		// we've just ticked a new line
		QLineSeries* new_series = new QLineSeries(chart);

		new_series->setName(QString::fromStdString(line_name));

		chart->addSeries(new_series);
	} else if (!now_checked && affected_line != nullptr) {
		// we've just unticked a line
		chart->removeSeries(affected_line);

		affected_line->deleteLater();
	}

	refresh();
}

QtCharts::QLineSeries* DBGraph::get_line (std::string name) const {
	QString qname = QString::fromStdString(name);

	for (auto s : chart->series()) {
		if (s != nullptr && s->name() == qname)
			return dynamic_cast<QLineSeries*>(s);
	}

	return nullptr;
}

void DBGraph::recreateAxes () {
	// QChart::createDefaultAxes not only creates some axes, but also rescales the chart
	// to the data. otherwise, we'd probably have to mess around with the mins and maxes
	// of all the lines ourselves.
	chart->createDefaultAxes();

	// remove the axes QChart::createDefaultAxes just made for us.
	for (auto axis : chart->axes())
		chart->removeAxis(axis);

	// bit dodgy: for some reason QChart::createDefaultAxes deletes the existing axes,
	// instead of just removing them. that means we have to remake our axes from scratch
	// instead of just calling addAxis again.
	x_axis = new QDateTimeAxis(this);
	x_axis->setFormat("yyyy-MM-dd HH:mm:ss:z");
	x_axis->setTitleText("Date");

	y_axis = new QValueAxis(this);
	y_axis->setTitleText("Value");

	chart->addAxis(x_axis, Qt::AlignBottom);
	chart->addAxis(y_axis, Qt::AlignLeft);

	// for axes to work you need to attach them to the chart *before* the series, so we
	// need to re-attach them.
	for (auto s : chart->series()) {
		s->attachAxis(x_axis);
		s->attachAxis(y_axis);
	}
}

std::string DBGraph::line_name (std::string table_name, std::string column_name) {
	return table_name + "." + column_name;
}

std::string DBGraph::query_string (std::string table, std::string sort_by) {
	std::string q_str = "select * from " + table;
	if (!sort_by.empty())
		q_str += " order by " + sort_by + " asc";
	return q_str + ";";
}
