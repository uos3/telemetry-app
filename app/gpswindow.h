#ifndef GPSWINDOW_H
#define GPSWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QTableView>
#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class gpswindow;
}

class gpswindow : public QWidget
{
    Q_OBJECT

public:
    explicit gpswindow(QWidget *parent = 0);
    ~gpswindow();

private slots:
    void on_refreshButton_clicked();
    void on_generateGraphButton_clicked();

private:
    Ui::gpswindow *ui;
    QTableView *gps_tableView;
    QSqlTableModel *model;
};

#endif // GPSWINDOW_H
