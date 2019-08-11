#pragma once

#include "packet.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>


class DBTable : public QWidget {
	Q_OBJECT

public:
	explicit DBTable (QSqlDatabase& db, std::string table,
	                  QWidget* parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags(),
	                  std::string sort_by="frame_id");

	QSqlQueryModel* get_model ();

	void refresh ();

private:
	static std::string query_string (std::string table, std::string sort_by="");

	static const int MARGINS = 0;

	QSqlDatabase& db;
	std::string table;
	std::string sort_by;

	QSqlQueryModel* model;
	QTableView* view;
};
