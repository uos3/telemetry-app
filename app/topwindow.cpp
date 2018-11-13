#include "topwindow.h"
#include "ui_topwindow.h"
#include "db.h"
#include "QDateTime"
#include "datawindow.h"


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
void topwindow::openDataWindow(std::string table_name)
{
    // Open status data window
    newDataWindow = new datawindow(table_name);
    newDataWindow -> show();
}

void topwindow::openCurrentDataWindow()
{
    // Open Current Data window
    showNewCurrentStatusWindow = new currentstatus();

    showNewCurrentStatusWindow -> show();
}

void topwindow::on_CurrentDataButton_clicked()
{
    // Detected current data button clicked
    // We should try to open the current data window
    openCurrentDataWindow();
}

void topwindow::on_StatusButton_clicked()
{
    // Detected status button clicked
    // We should try to open the second window
    openDataWindow("status");
}



void topwindow::on_GPSButton_clicked()
{
    // Detected GPS button clicked
    // We should try and open the current data window
    openDataWindow("gps");
}
