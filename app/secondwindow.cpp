#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "db.h"
#include "QString"
#include "QSql"
#include "QSqlRecord"
#include <QTableWidget>
#include <QDesktopWidget>
#include <QApplication>

QString current_query_string = "SELECT * FROM new_schema.status";
QString column_query_string = "SELECT column_name FROM information_schema.columns WHERE table_name = 'status' and table_schema = 'new_schema' ";
QString result = "";
QStringList column_names;
int result_2 = 0;

secondwindow::secondwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    DB("localhost","testdata","test_account","password");
    QSqlQuery query;
    if (query.exec(column_query_string)){
        qDebug("Information columns success");
    }
    else{
        qDebug("query unsuccessful");
    }
    QSqlRecord rec = query.record();
    int testiteration = rec.indexOf("Column_name");
    while(query.next()){
        column_names.append(query.value(testiteration).toString());
    }
    setWindowTitle("CURRENT DATA");
    ui -> new_table ->setRowCount(5);
    ui -> new_table ->setColumnCount(query.size());
    ui -> new_table ->setHorizontalHeaderLabels(column_names);
    ui -> new_table ->horizontalHeader()->setStretchLastSection(true);
    ui -> new_table ->setGeometry(0,0,1250,200);
}


secondwindow::~secondwindow()
{
    delete ui;
}


void secondwindow::on_pushButton_3_clicked()
{
    QSqlQuery q_1;
    if (q_1.exec(column_query_string)){
        qDebug("Information columns success");
    }
    else{
        qDebug("query unsuccessful");
    }
    QSqlRecord rec = q_1.record();
    int testiteration = rec.indexOf("Column_name");
    int no_columns = q_1.size();
    while(q_1.next()){
        column_names.append(q_1.value(testiteration).toString());
    }

    QSqlQuery q;
    if (q.exec(current_query_string)){
        qDebug("query successfully exectued on dummygps table within testdata schema");

    }else {
        qDebug("query unsuccesful");
    }
    for (int seek_counter =0 ; seek_counter < 5; ++seek_counter){
        q.next();
        for (int row_counter = 0; row_counter < no_columns; ++row_counter){
            QString result = q.value(row_counter).toString();
            ui -> new_table ->setItem(seek_counter, row_counter,new QTableWidgetItem(result) );
        }
        }


    qDebug()<<q.seek(2);
    ui -> new_table ->resizeColumnsToContents();
    ui -> new_table ->showMaximized();
}
