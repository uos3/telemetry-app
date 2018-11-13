#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QTableView>
#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class datawindow;
}

class datawindow : public QWidget
{
    Q_OBJECT

public:
    explicit datawindow(std::string table_name, QWidget *parent = 0);
    ~datawindow();
    std::string table_name;

private slots:
    void on_refreshButton_clicked();
    void on_generateGraphButton_clicked();
    void load_Data();

private:
    Ui::datawindow *ui;
    QTableView *data_tableView;
    QSqlTableModel *model;

};

#endif // DATAWINDOW_H
