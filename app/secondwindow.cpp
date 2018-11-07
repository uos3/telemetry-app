#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "db.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QTableView>
#include <QSqlTableModel>
#include "secrets/secrets.h"
#include <QDebug>

secondwindow::secondwindow(QWidget *parent): QWidget(parent), ui(new Ui::secondwindow)
{

    // Setup the UI for the status data window
    ui->setupUi(this);

    // Connect to the cubesat database
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup the database model
    this->model = new QSqlTableModel(parent, read_db.get_database());
    this->model->setTable("status");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    // Get the table view
    QTableView *view = ui->status_tableView;

    // Input model into table view
    view->setModel(this->model);

    // Sort table view by first column (Should be pack ID) in descending order
    view->sortByColumn(0,Qt::DescendingOrder);

    // Display the tableview
    view->show();

}


secondwindow::~secondwindow()
{
    // Destructor
}


void secondwindow::on_refreshButton_clicked()
{
    // Detected refresh button clicked
    // We should try to reload and display the data

    // Connect to the cubesat database
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);

    // Setup the database model
    this->model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->model->setTable("status");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    // Get the table view
    QTableView *view = ui->status_tableView;

    // Input model into table view
    view->setModel(this->model);

    // Sort the table view by first column (Should be pack ID) in decending order
    view->sortByColumn(0,Qt::DescendingOrder);

    // Display the tableview
    view->show();
}


void secondwindow::on_generateGraphButton_clicked()
{
    // TODO #enhancement: Graphing functionality is currently unimplemented

    // Get the selection model from the tableview
    QItemSelectionModel *select = ui->status_tableView->selectionModel();

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

            qDebug() << ui->status_tableView->model()->data(ui->status_tableView->model()->index(i,columnIndex)).toString();
        }
    }
}
















