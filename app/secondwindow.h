#pragma once

#include <QWidget>
#include <QTableWidget>
#include <QMainWindow>

namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = 0);
    ~secondwindow();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::secondwindow *ui;

    QTableWidget * new_table;
};
