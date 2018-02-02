#include <vector>
#include <tuple>

#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QtNetwork>

#include "uploader.h"
#include "db.h"
#include "secrets/secrets.h"
#include "packet.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
	w.show();

	// test db
//	DB mydb(secrets::db_hostname, secrets::db_dbname, secrets::db_username, secrets::db_password);
//	QString fields = "id, tstamp, battery_voltage, 5v_current";
//	QSqlQuery qu = mydb.get("dummydata", fields);
//	while (qu.next()) {
//		QList<QPair<QString, QString>> this_row = DB::row(qu, fields);
//		for (auto col: this_row) {
//			qDebug() << col.first << col.second;
//		}
//	}

	// test network stuff - local test server
//	Uploader up;
//	up.upload();

	// test network stuff - real server
//	Uploader loader(secrets::address);
//	std::vector<std::tuple<QString, QString>> body;
//	body.push_back(std::make_tuple("app_key", secrets::app_key));
//	body.push_back(std::make_tuple("battery_voltage", "2.533"));
//	loader.upload(body);

	// test packet stuff
	status my_status = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
						 "l", "m", "n", "o", "p", "q" };
	data test_data = { ._td = { "hello" } };
	data gps_data = { ._gps = { "gp", 5, 50.f, -1.f, 30.f, 1.f, 2.f, 3.f, 4.f } };
	data imu_data = { ._imu = { "im", 6, {1,1,1,1,1}, {2,2,2,2,2}, {3,3,3,3,3}, {4,4,4,4,4}, {5,5,5,5,5}, {6,6,6,6,6}, {7,7,7,7,7}, {8,8,8,8,8}, {9,9,9,9,9} } };
	data img_data = { ._img = { "im", 7, 0, 1, 2, "world" } };
//	data health_data = { ._health = { } }; // TODO
	qDebug() << my_status.antenna_deployment;
	qDebug() << test_data._td.member;
	qDebug() << gps_data._gps.sequence_id;
	qDebug() << imu_data._imu.timestamp;
	qDebug() << img_data._img.image_data;
//	qDebug() << health_data._health.obc_temperature; // TODO

	return a.exec();
}