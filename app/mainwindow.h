#pragma once

#include "db.h"

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QDockWidget>


class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(
		const DB& db,
		QWidget *parent = nullptr,
		Qt::WindowFlags flags = Qt::WindowFlags());

private:
	/* TODO #refactor: name */
	void init();

	const DB& db;
	QSqlTableModel* table_model;
	QTableView* table_view;
	QDockWidget* dock;
};
