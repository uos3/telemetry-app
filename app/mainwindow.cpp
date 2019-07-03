#include "mainwindow.h"


MainWindow::MainWindow (const DB& db, QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags), db(db)
	, table_model(nullptr), table_view(nullptr), dock(nullptr) {
	init();
}

void MainWindow::init () {
	table_model = new QSqlTableModel(this, db.get_database());
	table_model->setTable("frames");
	table_model->setEditStrategy(QSqlTableModel::OnRowChange);
	table_model->setSort(1, Qt::DescendingOrder);
	table_model->select();
	QObject::connect(&db, &DB::packet_stored,
		[this](const Packet& p){ Q_UNUSED(p); this->table_model->select(); });

	table_view = new QTableView(this);
	table_view->setModel(table_model);

	dock = new QDockWidget("frames", this);
	dock->setWidget(table_view);

	addDockWidget(Qt::BottomDockWidgetArea, dock);
}
