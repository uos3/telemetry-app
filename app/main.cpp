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
#include "reader.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
	w.show();

	// test packet stuff
//	status my_status = { ":)", 0, true, "st", 1.f, 2.f, 3.f, 4.f, 5.f, false, 1,
//						 2, {true,false,true,false,true,false}, 6.f, 7.f, 8.f,
//						 9.f };
//	data test_data = { ._td = { "hello" } };
//	data gps_data = { ._gps = { "gp", 5, 50.f, -1.f, 30.f, 1.f, 2.f, 3.f, 4.f } };
//	data imu_data = { ._imu = { "im", 6, {1,1,1,1,1}, {2,2,2,2,2}, {3,3,3,3,3},
//								{4,4,4,4,4}, {5,5,5,5,5}, {6,6,6,6,6},
//								{7,7,7,7,7}, {8,8,8,8,8}, {9,9,9,9,9} } };
//	data img_data = { ._img = { "im", 7, 0, 1, 2, "world" } };
//	data health_data = { ._health = { "hl", 8, 1.f, 2.f, 3.f, 4.f, 5, 6, false,
//									  7.f, 8, 9, 10.f, 11.f, 12.f, 13.f, 14.f,
//									  15.f, 16.f, 17.f, 18.f, 19.f, 20.f, 21.f,
//									  22.f, 23.f, 24.f, {true,true,true, true,
//									  true,true}, {true,true,true,true,true,
//									  true}, 25, 26, 27.f, 28.f, 29, 30, 31.f,
//									  32.f, 33, 34, 35.f, 36.f, 37, 38, 39.f,
//									  40.f, 41, 42, 43.f, 44.f, 45, 46, 47.f,
//									  48.f, 49.f, 50.f, 51.f, 52.f } };
//
//	packet my_packet = { my_status, gps_data };
//	qDebug() << "status:" << my_packet._status.spacecraft_id
//			 << "  data:" << my_packet._data._gps.sequence_id;
	Reader r;
	r.testing();

	return a.exec();
}