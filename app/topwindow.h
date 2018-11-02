#ifndef TOPWINDOW_H
#define TOPWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "secondwindow.h"
#include "gpswindow.h"

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
    void openSecondWindow();
    void openGPSWindow();
private slots:
    void on_StatusButton_clicked();
    void on_CurrentDataButton_clicked();
    void on_GPSButton_clicked();
private:
    secondwindow *showNewSecondWindow;
    gpswindow *showNewGPSWindow;
private:
    Ui::topwindow *ui;
};

#endif // TOPWINDOW_H
