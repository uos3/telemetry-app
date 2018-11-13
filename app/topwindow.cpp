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
    openCurrentDataWindow();
}

void topwindow::on_StatusButton_clicked(){openDataWindow("status");}
void topwindow::on_GPSButton_clicked(){openDataWindow("gps");}
void topwindow::on_FramesButton_clicked(){openDataWindow("frames");}
void topwindow::on_ConfigButton_clicked(){openDataWindow("config");}
void topwindow::on_IMUButton_clicked(){openDataWindow("imu");}
void topwindow::on_ImgButton_clicked(){openDataWindow("img");}
void topwindow::on_HealthButton_clicked(){openDataWindow("health");}

