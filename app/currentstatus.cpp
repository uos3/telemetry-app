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

    // Setup the UI for the status data window
    ui->setupUi(this);

    // Connect to the cubesat database
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);



    // Setup the database model for the status
    this->status_model = new QSqlTableModel(parent, read_db.get_database());
    this->status_model->setTable("status");
    this->status_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->status_model->select();


    // Setup the database model for the GPS
    this->gps_model = new QSqlTableModel(parent, read_db.get_database());
    this->gps_model->setTable("gps");
    this->gps_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->gps_model->select();

    // Get the status tableview
    QTableView *status_view = ui->status_tableView;

    // Input status model into status tableview
    status_view->setModel(this->status_model);
    status_view->sortByColumn(0,Qt::DescendingOrder);

    // Hide all but the most recent 5 rows of data
    for (int i = 5; i< status_view->model()->rowCount(); i++)
    {
        status_view->hideRow(i);
    }

    // Display the status tableview
    status_view->show();

    // get the GPS tableview
    QTableView *gps_view = ui->gps_tableView;

    // Input GPS model into GPS tableview
    gps_view->setModel(this->gps_model);
    gps_view->sortByColumn(0,Qt::DescendingOrder);

    // Hide all but the most recent 5 rows of data
    for (int i = 5; i< gps_view->model()->rowCount(); i++)
    {
        gps_view->hideRow(i);
    }

    //Display the GPS tableview
    gps_view->show();
}


currentstatus::~currentstatus()
{
    // Destructor
}


void currentstatus::on_refreshButton_clicked()
{
    // TODO: #CleanUp: Duplicate code on setup and refresh could be put into one function

    // Detected refresh button clicked
    // We should try to reload and display the data

    // Connect to the cubesat database
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);



    // Setup the database model for the status
    this->status_model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->status_model->setTable("status");
    this->status_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->status_model->select();


    // Setup the database model for the GPS
    this->gps_model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->gps_model->setTable("gps");
    this->gps_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->gps_model->select();

    // Get the status tableview
    QTableView *status_view = ui->status_tableView;

    // Input status model into status tableview
    status_view->setModel(this->status_model);
    status_view->sortByColumn(0,Qt::DescendingOrder);

    // Hide all but the most recent 5 rows of data
    for (int i = 5; i< status_view->model()->rowCount(); i++)
    {
        status_view->hideRow(i);
    }

    // Display the status tableview
    status_view->show();

    // get the GPS tableview
    QTableView *gps_view = ui->gps_tableView;

    // Input GPS model into GPS tableview
    gps_view->setModel(this->gps_model);
    gps_view->sortByColumn(0,Qt::DescendingOrder);

    // Hide all but the most recent 5 rows of data
    for (int i = 5; i< gps_view->model()->rowCount(); i++)
    {
        gps_view->hideRow(i);
    }

    //Display the GPS tableview
    gps_view->show();
}

















