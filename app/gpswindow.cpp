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
    // Setup the UI for the GPS data window
    ui->setupUi(this);

    // Connect to the cubesat database
    DB read_db("cubesat.db");
    read_db.connect(secrets::username, secrets::password);


    // Setup the database model
    this->model = new QSqlTableModel(parent, read_db.get_database());
    this->model->setTable("gps");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    // Get the table view
    QTableView *view = ui->gps_tableView;

    // Input model into table view
    view->setModel(this->model);

    // Sort table view by first column (Should be pack ID) in descending order
    view->sortByColumn(0,Qt::DescendingOrder);

    // Display the tableview
    view->show();

}


gpswindow::~gpswindow()
{
    // Destructor
}


void gpswindow::on_refreshButton_clicked()
{

    // TODO: #CleanUp: Duplicate code on setup and refresh could be put into one function

    // Detected refresh button clicked
    // We should try to reload and display the data

    // Connect to the cubesat database
    DB read_db("cubesat.db");
    read_db.connect(secrets::username, secrets::password);


    // Setup the database model
    this->model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->model->setTable("gps");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    // Get the table view
    QTableView *view = ui->gps_tableView;

    // Input model into table view
    view->setModel(this->model);

    // Sort the table view by first column (Should be pack ID) in decending order
    view->sortByColumn(0,Qt::DescendingOrder);

    // Display the tableview
    view->show();
}


void gpswindow::on_generateGraphButton_clicked()
{
    // TODO #enhancement: Graphing functionality is currently unimplemented

    // Get the selection model from the tableview
    QItemSelectionModel *select = ui->gps_tableView->selectionModel();

    // Output the number of selected columns
    qDebug() << select->selectedColumns().length();

    // Check to see if the number of selected columns is 1 (So we can graph it)
    if (select->selectedColumns().length() == 1)
    {
        // Number of selected columns is 1

        // Get the index of the selected column
        int columnIndex = select->selectedIndexes().value(0).column();

        // Output the number of indexes that we have selected (Should be number of rows)
        qDebug() <<  select->selectedIndexes().length();

        // Iterate through the selected indexes and output to the debug log

        // TODO #enhancement This data should be given to a graphing module which would
        for (int i = 0; i <= select->selectedIndexes().length(); i++)
        {
            qDebug() << i;

            qDebug() << ui->gps_tableView->model()->data(ui->gps_tableView->model()->index(i,columnIndex)).toString();
        }
    }
}
















