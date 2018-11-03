#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "db.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QTableView>
#include <QSqlTableModel>
#include "secrets/secrets.h"
#include <QDebug>

QString current_query_string = "SELECT * FROM cubesat.status";
QString column_query_string = "SELECT column_name FROM information_schema.columns WHERE table_name = 'status' and table_schema = 'cubesat'";
QString result = "";
QStringList column_names;
int result_2 = 0;
int startPosition = 0;

secondwindow::secondwindow(QWidget *parent): QWidget(parent), ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    // Init
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup table view
    this->model = new QSqlTableModel(parent, read_db.get_database());
    this->model->setTable("status");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    QTableView *view = ui->status_tableView;

    view->setModel(this->model);
    view->sortByColumn(0,Qt::DescendingOrder);
    view->show();

}


secondwindow::~secondwindow()
{
    // Destructor
}


void secondwindow::on_refreshButton_clicked()
{
    // qDebug("THE REFRESH BUTTON WAS PRESSED");
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup table view
    this->model = new QSqlTableModel(this->parent(), read_db.get_database());
    this->model->setTable("status");
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->model->select();

    QTableView *view = ui->status_tableView;

    view->setModel(this->model);
    view->sortByColumn(0,Qt::DescendingOrder);
    view->show();
}


void secondwindow::on_generateGraphButton_clicked()
{
    qDebug("THE GRAPH BUTTON WAS PRESSED");
    QItemSelectionModel *select = ui->status_tableView->selectionModel();

    qDebug() << select->selectedColumns().length();
    if (select->selectedColumns().length() == 1)
    {

        qDebug("We have one column");

        int columnIndex = select->selectedIndexes().value(0).column();

        qDebug() <<  select->selectedIndexes().length();
        for (int i = 0; i <= select->selectedIndexes().length(); i++)
        {
            qDebug() << i;

            qDebug() << ui->status_tableView->model()->data(ui->status_tableView->model()->index(i,columnIndex)).toString();
        }
    }
}
















