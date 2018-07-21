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
#include "buffer.h"

//int packSize = 3136; // Number of bits per packet
//int packSize = 88; // Number of bits per packet

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
	w.show();

	// test packet stuff
//	Status my_status = { ":)", 0, true, "st", 1.f, 2.f, 3.f, 4.f, 5.f, false, 1,
//						 2, {true,false,true,false,true,false}, 6.f, 7.f, 8.f,
//						 9.f };
//	Data test_payload = { .td = { "hello" } };
//	Data gps_payload = { .gps = { "gp", 5, 50.f, -1.f, 30.f, 1.f, 2.f, 3.f, 4.f } };
//	Data imu_payload = { .imu = { "im", 6, {1,1,1,1,1}, {2,2,2,2,2}, {3,3,3,3,3},
//								{4,4,4,4,4}, {5,5,5,5,5}, {6,6,6,6,6},
//								{7,7,7,7,7}, {8,8,8,8,8}, {9,9,9,9,9} } };
//	Data img_payload = { .img = { "im", 7, 0, 1, 2, "world" } };
//	Data health_payload = { .health = { "hl", 8, 1.f, 2.f, 3.f, 4.f, 5, 6, false,
//									  7.f, 8, 9, 10.f, 11.f, 12.f, 13.f, 14.f,
//									  15.f, 16.f, 17.f, 18.f, 19.f, 20.f, 21.f,
//									  22.f, 23.f, 24.f, {true,true,true, true,
//									  true,true}, {true,true,true,true,true,
//									  true}, 25, 26, 27.f, 28.f, 29, 30, 31.f,
//									  32.f, 33, 34, 35.f, 36.f, 37, 38, 39.f,
//									  40.f, 41, 42, 43.f, 44.f, 45, 46, 47.f,
//									  48.f, 49.f, 50.f, 51.f, 52.f } };
//
//	Packet my_packet = { my_status, gps_payload };
//	qDebug() << "status:" << my_packet.status.spacecraft_id
//			 << "  data:" << my_packet.payload.gps.sequence_id;

	Buffer b;
//	b.from_file("test.txt");//, packSize);
	b.from_file("testinput.bin");//, packSize);
	qDebug() << "\nbuffer:\n";
	{
		QDebug p = qDebug();
		for (unsigned int i=0;i<b.getLen();i++) { p << b.getBuf()[i]; } // TODO: doesn't work
		p << "\n";
	}

//	qDebug() << "\nReading bits from the file:";
//	uint8_t  ch1 = (uint8_t)b.get(23 * 8 + 0,  8);
//	uint8_t  ch2 = (uint8_t)b.get(11 * 8 + 2,  6);
//	uint32_t ch3 =          b.get(22 * 8 + 0, 15);
//	uint32_t ch4 =          b.get(22 * 8 + 4, 15);

	// for whole test.txt, expect 120, 37, 12988, 11203
	// for whole testinput.bin, expect 31, 2, 29455, 12541
//	qDebug() << ch1 << ", " << ch2 << ", " << ch3 << ", " << ch4;

//	qDebug() << "mock packet parse:";
//	b.setPos(64);
//	uint32_t ptype = b.get(16);
//	qDebug() << "packet type: " << ptype;
//	b.setPos(80);
//	uint16_t spc_id = static_cast<uint16_t>(b.get(16));
//	char spacecraft_id[2] = { (char)(spc_id & 0xFF), (char)(spc_id >> 8) };
//	qDebug() << "spacecraft id: " << spacecraft_id[0] << spacecraft_id[1];
//	int time = b.get(32);
//	qDebug() << "time" << time;
//	bool time_source = (bool)b.get(1);
//	qDebug() << "time_source" << time_source;
//	uint16_t seq_id = static_cast<uint16_t>(b.get(16));
//	char sequence_id[2] = { (char)(seq_id & 0xFF), (char)(seq_id >> 8) };
//	qDebug() << "sequence id: " << sequence_id[0] << sequence_id[1];
//	uint8_t obc_temperature = b.get(8);
//	qDebug() << "obc_temperature" << obc_temperature;
//	uint8_t battery_temperature = b.get(8);
//	qDebug() << "battery_temperature" << battery_temperature;
//	uint8_t battery_voltage = b.get(8);
//	qDebug() << "battery_voltage" << battery_voltage;
//	uint8_t battery_current = b.get(8);
//	qDebug() << "battery_current" << battery_current;
//	uint8_t charge_current = b.get(8);
//	qDebug() << "charge_current" << charge_current;
//	bool antenna_deployment = b.get(1);
//	qDebug() << "antenna_deployment" << antenna_deployment;
//	uint16_t data_pending = b.get(16);
//	qDebug() << "data_pending" << data_pending;
//	uint8_t reboot_count = b.get(8);
//	qDebug() << "reboot_count" << reboot_count;
//	bool rails_status[6] = {
//		(bool)b.get(1), (bool)b.get(1), (bool)b.get(1),
//		(bool)b.get(1), (bool)b.get(1), (bool)b.get(1)
//	};
//	qDebug() << "rails_status" << rails_status[0] << rails_status[1] <<
//			   rails_status[2] << rails_status[3] << rails_status[4] <<
//			   rails_status[5];
//	uint8_t rx_temperature = b.get(8);
//	qDebug() << "rx_temperature" << rx_temperature;
//	uint8_t tx_temperature = b.get(8);
//	qDebug() << "tx_temperature" << tx_temperature;
//	uint8_t pa_temperature = b.get(8);
//	qDebug() << "pa_temperature" << pa_temperature;
//	uint8_t rx_noisefloor = b.get(8);
//	qDebug() << "rx_noisefloor" << rx_noisefloor;
//	qDebug() << "final pos" << b.getPos();

//	qDebug() << "length:" << b.getLen();
//	for (int i=0;i<b.getLen()*8;i++) {
//		qDebug() << b.getPos() << ":" << b.get(1);
//	}

	Packet p;
	from_buffer(p, b);

	qDebug() << "type:" << (int)p.type;
	qDebug() << "status:" << p.status.spacecraft_id[0]
						  << p.status.spacecraft_id[1]
			 << "  status end:" << p.status.rx_noisefloor
			 << "  data:" << (uint8_t)p.payload.gps.sequence_id[0]
						  << (uint8_t)p.payload.gps.sequence_id[1]
			 << "  data end:" << (uint8_t)p.payload.gps.TDOP;

	return a.exec();
}