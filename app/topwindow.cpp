#include "topwindow.h"
#include "ui_topwindow.h"
#include "db.h"
#include "QDateTime"
#include "secondwindow.h"
#include "gpswindow.h"


topwindow::topwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::topwindow)
{
    ui->setupUi(this);
}

topwindow::~topwindow()
{
    delete ui;
}
void topwindow::openSecondWindow()
{
    showNewSecondWindow = new secondwindow();

    showNewSecondWindow -> show();
}

void topwindow::openGPSWindow()
{
    showNewGPSWindow = new gpswindow();

    showNewGPSWindow -> show();
}


void topwindow::on_StatusButton_clicked()
{
    openSecondWindow();
}

void topwindow::on_CurrentDataButton_clicked()
{
    //openSecondWindow();
}

void topwindow::on_GPSButton_clicked()
{
    openGPSWindow();
}
