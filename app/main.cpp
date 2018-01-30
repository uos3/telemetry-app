#include <vector>
#include <tuple>

#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QtNetwork>

#include "uploader.h"
#include "db.h"
#include "secrets/secrets.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	w.show();

	// test db.
	DB mydb(secrets::db_hostname, secrets::db_dbname, secrets::db_username, secrets::db_password);
	QSqlQuery qu = mydb.get("mydata", "id, tstamp, battery_voltage, 5v_current");
	while (qu.next()) {
		QString id = qu.value(0).toString();
		QString tstamp = qu.value(1).toString();
		QString battery_voltage = qu.value(2).toString();
		QString fiveV_current = qu.value(3).toString();
		qDebug() << id << tstamp << battery_voltage << fiveV_current;
	}

	// test network stuff
//	Uploader up;
//	up.upload();

	// real test stuff
//	Uploader loader(secrets::address);
//	std::vector<std::tuple<QString, QString>> body;
//	body.push_back(std::make_tuple("app_key", secrets::app_key));
//	body.push_back(std::make_tuple("battery_voltage", "2.533"));
//	loader.upload(body);

    return a.exec();
}