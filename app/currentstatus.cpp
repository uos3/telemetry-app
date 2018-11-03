#include "currentstatus.h"
#include "ui_currentstatus.h"
#include "db.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QTableView>
#include <QSqlTableModel>
#include "secrets/secrets.h"
#include <QDebug>

currentstatus::currentstatus(QWidget *parent): QWidget(parent), ui(new Ui::currentstatus)
{
    ui->setupUi(this);
    // Init
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);



    // Setup table view
    this->status_model = new QSqlTableModel(parent, read_db.get_database());
    this->status_model->setTable("status");
    this->status_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->status_model->select();


    // Setup table view
    this->gps_model = new QSqlTableModel(parent, read_db.get_database());
    this->gps_model->setTable("gps");
    this->gps_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->gps_model->select();

    QTableView *status_view = ui->status_tableView;

    status_view->setModel(this->status_model);
    status_view->sortByColumn(0,Qt::DescendingOrder);

    for (int i = 5; i< status_view->model()->rowCount(); i++)
    {
        status_view->hideRow(i);
    }

    status_view->show();


    QTableView *gps_view = ui->gps_tableView;

    gps_view->setModel(this->gps_model);
    gps_view->sortByColumn(0,Qt::DescendingOrder);

    for (int i = 5; i< gps_view->model()->rowCount(); i++)
    {
        gps_view->hideRow(i);
    }

    gps_view->show();
}


currentstatus::~currentstatus()
{
    // Destructor
}


void currentstatus::on_refreshButton_clicked()
{
    // qDebug("THE REFRESH BUTTON WAS PRESSED");

    /*
    // Init
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup table view
    this->status_model = new QSqlTableModel(parent, read_db.get_database());
    this->status_model->setTable("status");
    this->status_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->status_model->select();


    // Setup table view
    this->gps_model = new QSqlTableModel(parent, read_db.get_database());
    this->gps_model->setTable("gps");
    this->gps_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->gps_model->select();

    QTableView *status_view = ui->status_tableView;

    status_view->setModel(this->status_model);
    status_view->sortByColumn(0,Qt::DescendingOrder);
    status_view->show();


    QTableView *gps_view = ui->gps_tableView;

    gps_view->setModel(this->gps_model);
    gps_view->sortByColumn(0,Qt::DescendingOrder);
    gps_view->show();
    */
}

















