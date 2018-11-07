#include "topwindow.h"
#include "ui_topwindow.h"
#include "db.h"
#include "QDateTime"
#include "secondwindow.h"
#include "gpswindow.h"


topwindow::topwindow(QWidget *parent):QWidget(parent),ui(new Ui::topwindow)
{
    // Called on init
    // We should set up the ui for the top window:
    ui->setupUi(this);
}

topwindow::~topwindow()
{
    // Top window destructor
    delete ui;
}
void topwindow::openSecondWindow()
{
    // Open status data window
    showNewSecondWindow = new secondwindow();

    showNewSecondWindow -> show();
}

void topwindow::openGPSWindow()
{
    // Open GPS data window
    showNewGPSWindow = new gpswindow();

    showNewGPSWindow -> show();
}

void topwindow::openCurrentDataWindow()
{
    // Open Current Data window
    showNewCurrentStatusWindow = new currentstatus();

    showNewCurrentStatusWindow -> show();
}

void topwindow::on_StatusButton_clicked()
{
    // Detected status button clicked
    // We should try to open the second window
    openSecondWindow();
}

void topwindow::on_CurrentDataButton_clicked()
{
    // Detected current data button clicked
    // We should try to open the current data window
    openCurrentDataWindow();
}

void topwindow::on_GPSButton_clicked()
{
    // Detected GPS button clicked
    // We should try and open the current data window
    openGPSWindow();
}
