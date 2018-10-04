#include <vector>
#include <tuple>

#include <QApplication>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QObject>
#include <QtNetwork>

#include "buffer.h"
#include "cli.h"
#include "db.h"
#include "filehandler.h"
#include "mainwindow.h"
#include "packet.h"
//#include "secrets/secrets.h"
#include "uploader.h"

static const std::string file_path = "input.bin";
static const uint32_t packet_size = 3136;

int main (int argc, char* argv[]) {
	QApplication a(argc, argv);

	if (!cli(argc, argv)) {
		// Watch our binary file for new packets to be parsed/stored.
		FileHandler f(file_path, packet_size);

		// Display the GUI.
		MainWindow w;
		w.show();

		return a.exec();
	} else { return 0; }

	return a.exec();
}
