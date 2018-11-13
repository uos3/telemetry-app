#pragma once

#include <QWidget>
#include <QMainWindow>
#include "datawindow.h"
#include "currentstatus.h"

namespace Ui {
class topwindow;
}

class topwindow : public QWidget
{
    Q_OBJECT

public:
    explicit topwindow(QWidget *parent = 0);
    ~topwindow();
public slots:
    void openDataWindow(std::string table_name);
    void openCurrentDataWindow();
private slots:
    void on_StatusButton_clicked();
    void on_CurrentDataButton_clicked();
    void on_GPSButton_clicked();
    void on_FramesButton_clicked();
    void on_ConfigButton_clicked();
    void on_IMUButton_clicked();
    void on_ImgButton_clicked();
    void on_HealthButton_clicked();
private:
    datawindow *newDataWindow;
    currentstatus *showNewCurrentStatusWindow;
private:
    Ui::topwindow *ui;
};
