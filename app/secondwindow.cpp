#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "db.h"
#include <QTableWidget>
#include <QDesktopWidget>
#include <QApplication>
#include <QTableView>
#include <QSqlTableModel>
#include "secrets/secrets.h"

QString current_query_string = "SELECT * FROM cubesat.status";
QString column_query_string = "SELECT column_name FROM information_schema.columns WHERE table_name = 'status' and table_schema = 'cubesat'";
QString result = "";
QStringList column_names;
int result_2 = 0;
int startPosition = 0;

secondwindow::secondwindow(QWidget *parent): QWidget(parent), ui(new Ui::secondwindow)
{
    // Init
    DB read_db("localhost", "cubesat");
    read_db.connect(secrets::username, secrets::password);


    // Setup table view
    QSqlTableModel *model = new QSqlTableModel(parent, read_db.get_database());
    model->setTable("status");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    //model->setHeaderData(1, Qt::Horizontal, tr("Salary"));

    QTableView *view = new QTableView;
    view->setModel(model);
    // view->hideColumn(0); // don't show the ID
    view->show();
}


secondwindow::~secondwindow()
{
    // Destructor
}


void secondwindow::on_pushButton_3_clicked()
{

}


void secondwindow::on_pushButton_2_clicked()
{
    // We should move on by 5 rows
}
















