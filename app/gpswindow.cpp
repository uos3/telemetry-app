#include "gpswindow.h"
#include "ui_gpswindow.h"
#include "db.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QTableView>
#include <QSqlTableModel>
#include "secrets/secrets.h"
#include <QDebug>

gpswindow::gpswindow(QWidget *parent): QWidget(parent), ui(new Ui::gpswindow)
{
    ui->setupUi(this);
    // Init
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup table view
    this->model = new QSqlTableModel(parent, read_db.get_database());
    this->model->setTable("gps");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    QTableView *view = ui->gps_tableView;

    view->setModel(this->model);
    view->sortByColumn(0,Qt::DescendingOrder);
    view->show();

}


gpswindow::~gpswindow()
{
    // Destructor
}


void gpswindow::on_refreshButton_clicked()
{
    // qDebug("THE REFRESH BUTTON WAS PRESSED");
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup table view
    this->model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->model->setTable("gps");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    QTableView *view = ui->gps_tableView;

    view->setModel(this->model);
    view->sortByColumn(0,Qt::DescendingOrder);
    view->show();
}


void gpswindow::on_generateGraphButton_clicked()
{
    qDebug("THE GRAPH BUTTON WAS PRESSED");
    QItemSelectionModel *select = ui->gps_tableView->selectionModel();

    qDebug() << select->selectedColumns().length();
    if (select->selectedColumns().length() == 1)
    {

        qDebug("We have one column");

        int columnIndex = select->selectedIndexes().value(0).column();

        qDebug() <<  select->selectedIndexes().length();
        for (int i = 0; i <= select->selectedIndexes().length(); i++)
        {
            qDebug() << i;

            qDebug() << ui->gps_tableView->model()->data(ui->gps_tableView->model()->index(i,columnIndex)).toString();
        }
    }
}
















