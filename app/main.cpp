#include <vector>
#include <tuple>

#include <QApplication>
#include <QObject>
#include <QSqlDatabase>

#include "buffer.h"
#include "cli.h"
#include "db.h"
#include "input_file.h"
#include "input_socket.h"
#include "mainwindow.h"
#include "output_db.h"
#include "output_json.h"
#include "output_upload.h"
#include "secrets/secrets.h"
#include "uploader.h"


static const std::string file_path = "input.bin";
static const uint32_t packet_size = 3136 / 8;

int main (int argc, char* argv[]) {

	// If we've received commandline arguments, operate as a CLI program then exit.
	if (cli(argc, argv))
		return 0;

	QApplication a(argc, argv);

	// Watch for new packets to be dealt with.
	FileInput fi(file_path, packet_size);
	SocketInput si;

	// Set up outputs for new packets.
	JsonOutput jo;
	jo.listen_to(fi);
	jo.listen_to(si);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("cubesat.db");
	DBOutput dbo(db);
	if (db.open(QString::fromStdString(secrets::username),
				QString::fromStdString(secrets::password))) {
		dbo.listen_to(fi);
		dbo.listen_to(si);
	} else {
		qWarning("DB failed to connect.");
	}

	Uploader uploader("http://localhost:8080", secrets::app_key, "cooldude49");
	UploaderOutput uo(uploader);
	uo.listen_to(fi);
	uo.listen_to(si);

	// Show the main window.
	MainWindow window(db);
	QObject::connect(&dbo, &DBOutput::packet_output, &window, &MainWindow::refresh);
	window.show();

	return a.exec();
}
