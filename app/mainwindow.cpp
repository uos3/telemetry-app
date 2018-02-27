#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db.h"
//global row counter
int global_counter = 0;

QString full_query_string =
        "SELECT dummytable_id, battery_voltage, battery_current, "
        "solar_s2_current, rails_overcurrent_status, rail_2_overcurrent_count, "
        "rail_3_boot_count, rail_4_overcurrent_count, rail_6_current "
        "FROM dummy_data.dummytable";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DB("localhost","dummy_data","test_account","password");
    qDebug() << global_counter;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui ->label_6 ->setText("CURRENT ROW COUNTER");
    QSqlQuery query;
    query.exec(full_query_string);
    query.next();
    int dummytable_id = query.value(0). toInt();
    float battery_voltage = query.value(1).toFloat();
    float battery_current = query.value(2).toFloat();
    float solar_s2_current = query.value(3).toFloat();
    float rails_overcurrent_status = query.value(4).toFloat();
    float rail_2_overcurrent_count = query.value(5).toFloat();
    float rail_3_boot_count = query.value(6).toFloat();
    float rail_4_overcurrent_count = query.value(7).toFloat();
    float rail_6_current = query.value(8).toFloat();
    qDebug() <<dummytable_id<<battery_voltage<<battery_current<<solar_s2_current<<rails_overcurrent_status<<rail_2_overcurrent_count<<rail_3_boot_count<<rail_4_overcurrent_count<<rail_6_current;
    global_counter = 1;
    qDebug() <<global_counter;
    QString row_number = QString::number(dummytable_id,'dummytable_id',0);
    QString bat_volt = QString::number(battery_voltage,'battery_voltage',6);
    QString bat_cur = QString::number(battery_current,'battery_current',6);
    QString sol_s2_cur = QString::number(solar_s2_current,'solar_s2_current',6);
    QString rails_overcur_stat = QString::number(rails_overcurrent_status,'rails_overcurrent_status',6);
    QString rail_2_overcur_coun = QString::number(rail_2_overcurrent_count,'rail_2_overcurrent_count',6);
    QString rail_3_boot_coun = QString::number(rail_3_boot_count,'rail_3_boot_count',6);
    QString rail_4_overcur_coun = QString::number(rail_4_overcurrent_count, 'rail_4_overcurrent_count',6);
    QString rail_6_cur = QString::number(rail_6_current,'rail_6_current',6);
ui ->label_10 ->setText(bat_volt);
ui ->label_11 ->setText(bat_cur);
ui ->label_12 ->setText(sol_s2_cur);
ui ->label_13 ->setText(rails_overcur_stat);
ui ->label_14 ->setText(rail_2_overcur_coun);
ui ->label_15 ->setText(rail_3_boot_coun);
ui ->label_16 ->setText(rail_4_overcur_coun);
ui ->label_17 ->setText(rail_6_cur);
ui ->lcdNumber ->display(global_counter);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui ->label_6 ->setText("CURRENT ROW COUNTER");
    global_counter = global_counter + 1;
    QSqlQuery query;
    query.exec(full_query_string);
    query.seek(global_counter - 1);
    int dummytable_id = query.value(0). toInt();
    float battery_voltage = query.value(1).toFloat();
    float battery_current = query.value(2).toFloat();
    float solar_s2_current = query.value(3).toFloat();
    float rails_overcurrent_status = query.value(4).toFloat();
    float rail_2_overcurrent_count = query.value(5).toFloat();
    float rail_3_boot_count = query.value(6).toFloat();
    float rail_4_overcurrent_count = query.value(7).toFloat();
    float rail_6_current = query.value(8).toFloat();
    qDebug() <<dummytable_id<<battery_voltage<<battery_current<<solar_s2_current<<rails_overcurrent_status<<rail_2_overcurrent_count<<rail_3_boot_count<<rail_4_overcurrent_count<<rail_6_current;
    qDebug() <<global_counter;
    QString row_number = QString::number(dummytable_id,'dummytable_id',0);
    QString bat_volt = QString::number(battery_voltage,'battery_voltage',6);
    QString bat_cur = QString::number(battery_current,'battery_current',6);
    QString sol_s2_cur = QString::number(solar_s2_current,'solar_s2_current',6);
    QString rails_overcur_stat = QString::number(rails_overcurrent_status,'rails_overcurrent_status',6);
    QString rail_2_overcur_coun = QString::number(rail_2_overcurrent_count,'rail_2_overcurrent_count',6);
    QString rail_3_boot_coun = QString::number(rail_3_boot_count,'rail_3_boot_count',6);
    QString rail_4_overcur_coun = QString::number(rail_4_overcurrent_count, 'rail_4_overcurrent_count',6);
    QString rail_6_cur = QString::number(rail_6_current,'rail_6_current',6);
ui ->label_10 ->setText(bat_volt);
ui ->label_11 ->setText(bat_cur);
ui ->label_12 ->setText(sol_s2_cur);
ui ->label_13 ->setText(rails_overcur_stat);
ui ->label_14 ->setText(rail_2_overcur_coun);
ui ->label_15 ->setText(rail_3_boot_coun);
ui ->label_16 ->setText(rail_4_overcur_coun);
ui ->label_17 ->setText(rail_6_cur);
ui ->lcdNumber ->display(global_counter);

}

void MainWindow::on_pushButton_clicked()
{
    global_counter = global_counter - 1;
    if (global_counter > 0){
        QSqlQuery query;
        query.exec(full_query_string);
        query.seek(global_counter -1);
        int dummytable_id = query.value(0). toInt();
        float battery_voltage = query.value(1).toFloat();
        float battery_current = query.value(2).toFloat();
        float solar_s2_current = query.value(3).toFloat();
        float rails_overcurrent_status = query.value(4).toFloat();
        float rail_2_overcurrent_count = query.value(5).toFloat();
        float rail_3_boot_count = query.value(6).toFloat();
        float rail_4_overcurrent_count = query.value(7).toFloat();
        float rail_6_current = query.value(8).toFloat();
        qDebug() <<dummytable_id<<battery_voltage<<battery_current<<solar_s2_current<<rails_overcurrent_status<<rail_2_overcurrent_count<<rail_3_boot_count<<rail_4_overcurrent_count<<rail_6_current;
        qDebug() <<global_counter;
        QString row_number = QString::number(dummytable_id,'dummytable_id',0);
        QString bat_volt = QString::number(battery_voltage,'battery_voltage',6);
        QString bat_cur = QString::number(battery_current,'battery_current',6);
        QString sol_s2_cur = QString::number(solar_s2_current,'solar_s2_current',6);
        QString rails_overcur_stat = QString::number(rails_overcurrent_status,'rails_overcurrent_status',6);
        QString rail_2_overcur_coun = QString::number(rail_2_overcurrent_count,'rail_2_overcurrent_count',6);
        QString rail_3_boot_coun = QString::number(rail_3_boot_count,'rail_3_boot_count',6);
        QString rail_4_overcur_coun = QString::number(rail_4_overcurrent_count, 'rail_4_overcurrent_count',6);
        QString rail_6_cur = QString::number(rail_6_current,'rail_6_current',6);
    ui ->label_10 ->setText(bat_volt);
    ui ->label_11 ->setText(bat_cur);
    ui ->label_12 ->setText(sol_s2_cur);
    ui ->label_13 ->setText(rails_overcur_stat);
    ui ->label_14 ->setText(rail_2_overcur_coun);
    ui ->label_15 ->setText(rail_3_boot_coun);
    ui ->label_16 ->setText(rail_4_overcur_coun);
    ui ->label_17 ->setText(rail_6_cur);
    ui ->lcdNumber ->display(global_counter);
    } else {
        global_counter = 1;
        qDebug("COUNTER RESET TO 1");
        ui -> label_6 ->setText("COUNTER RESET TO 1 FOR NEXT BUTTON PRESS");
    }


}
