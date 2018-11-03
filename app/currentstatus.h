#ifndef CURRENTSTATUS_H
#define CURRENTSTATUS_H

#include <QWidget>
#include <QTableWidget>
#include <QTableView>
#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class currentstatus;
}

class currentstatus : public QWidget
{
    Q_OBJECT

public:
    explicit currentstatus(QWidget *parent = 0);
    ~currentstatus();

private slots:
    void on_refreshButton_clicked();

private:
    Ui::currentstatus *ui;
    QTableView *status_tableView;
    QSqlTableModel *status_model;
    QTableView *gps_tableView;
    QSqlTableModel *gps_model;
};

#endif // CURRENTSTATUS_H
