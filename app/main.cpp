#include <vector>
#include <tuple>

#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QtNetwork>

#include "uploader.h"
#include "secrets/secrets.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	w.show();

	// test network stuff
	Uploader up;
	up.upload();

	// "real" network stuff
//	Uploader loader(secrets::address);
//	std::vector<std::tuple<QString, QString>> body;
//	body.push_back(std::make_tuple("app_key", secrets::app_key));
//	body.push_back(std::make_tuple("battery_volage", "2.533"));
//	loader.upload(body);

    return a.exec();
}