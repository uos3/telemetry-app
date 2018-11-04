#pragma once

#include <QWidget>
#include <QMainWindow>
#include "secondwindow.h"

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
private slots:
    void on_CurrentStatusButton_clicked();

private:
    secondwindow *showNewWindow;
private:
    Ui::topwindow *ui;
};
