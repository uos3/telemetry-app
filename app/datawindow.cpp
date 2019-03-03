#include "datawindow.h"
#include "ui_datawindow.h"
#include "db.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QTableView>
#include <QSqlTableModel>
#include "secrets/secrets.h"
#include <QDebug>

datawindow::datawindow(std::string table_name, QWidget *parent): QWidget(parent), ui(new Ui::datawindow)
{
    this->table_name = table_name;
    // Setup the UI for the data window
    ui->setupUi(this);

    // Connect to the cubesat database
    load_Data();
}


datawindow::~datawindow()
{
    // Destructor
}

void datawindow::load_Data()
{
    // Connect to the cubesat database
    DB read_db("cubesat.db");
    read_db.connect(secrets::username, secrets::password);

    qDebug() << this->table_name.c_str();

    ui->table_title->setText(this->table_name.c_str());
    // Setup the database model
    this->model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->model->setTable(this->table_name.c_str());
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    // Get the table view
    QTableView *view = ui->data_tableView;

    // Input model into table view
    view->setModel(this->model);

    // Sort the table view by first column (Should be pack ID) in decending order
    view->sortByColumn(0,Qt::DescendingOrder);

    // Display the tableview
    view->show();
}

void datawindow::on_refreshButton_clicked()
{
    load_Data();
}


void datawindow::on_generateGraphButton_clicked()
{
    // TODO #enhancement: Graphing functionality is currently unimplemented

    // Get the selection model from the tableview
    QItemSelectionModel *select = ui->data_tableView->selectionModel();

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

            qDebug() << ui->data_tableView->model()->data(ui->data_tableView->model()->index(i,columnIndex)).toString();
        }
    }
}
















