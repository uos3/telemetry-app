#include "topwindow.h"
#include "ui_topwindow.h"
#include "db.h"
#include "QDateTime"
#include "secondwindow.h"

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
    showNewWindow = new secondwindow();

    showNewWindow -> show();
}

void topwindow::on_CurrentStatusButton_clicked()
{
    openSecondWindow();
}
