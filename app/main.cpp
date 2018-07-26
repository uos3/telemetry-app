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
#include "cli.h"

static const int packSize = 3136; // Number of bits per packet

int main (int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	// TEST PACKET STUFF
	// read packet
//	Buffer b;
//	b.from_file("testinput.bin", packSize);
//	qDebug() << "\nbuffer:\n";
//	{
//		QDebug p = qDebug();
//		for (unsigned int i=0;i<b.getLen();i++) { p << hex << b.get(8); }
//		p << "\n";
//	} b.setPos(0);
//
//	// parse
//	Packet p;
//	from_buffer(p, b);
//    qDebug() << "\ntype:" << static_cast<int>(p.type);
//	qDebug() << "status:" << p.status.spacecraft_id[0]
//						  << p.status.spacecraft_id[1]
//			 << "  status end:" << p.status.rx_noisefloor
//             << "\ndata:" << static_cast<uint8_t>(p.payload.gps.sequence_id[0])
//                          << static_cast<uint8_t>(p.payload.gps.sequence_id[1])
//			 << "  data end:" << p.payload.gps.TDOP;
//	qDebug("hash: %.16s  crc: %.2s\n", p.hash, p.crc);
//	/* for testinput.bin, should get:
//		type: 2
//		status: B B   status end: 92
//		data: 251 44  data end: 209
//		hash: UUUUUUUUUUUUUUUU crc: UU
//	*/

	const char* args[3] = { "app.exe", "parse", "testinput.bin" }; // simulated cli...
	cli(3, const_cast<char**>(args));

	return a.exec();
}
