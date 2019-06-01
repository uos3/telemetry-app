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
#include "input_file.h"
#include "input_socket.h"
#include "output_db.h"
#include "output_json.h"
#include "output_upload.h"
#include "secrets/secrets.h"
#include "topwindow.h"
#include "uploader.h"


static const std::string file_path = "input.bin";
static const uint32_t packet_size = 3136;

int main (int argc, char* argv[]) {

	if (!cli(argc, argv)) {
		QApplication a(argc, argv);

		// Watch our binary file for new packets to be parsed/stored.
		FileInput fi(file_path, packet_size);

		SocketInput si;

		JsonOutput jo;
		jo.listen_to(fi);
		jo.listen_to(si);

		DB db("cubesat.db");
		DBOutput dbo(db);
		if (db.connect(secrets::username, secrets::password)) {
			dbo.listen_to(fi);
			dbo.listen_to(si);
		} else {
			qWarning() << "DB failed to connect.";
		}

		Uploader uploader("http://localhost:8080", secrets::app_key, "cooldude49");
		UploaderOutput uo(uploader);
		uo.listen_to(fi);
		uo.listen_to(si);

		// Display the GUI.
        topwindow w;
		w.show();

		return a.exec();
	} else { return 0; }
}
