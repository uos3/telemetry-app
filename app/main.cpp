#include <vector>
#include <tuple>

#include <QApplication>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QObject>
#include <QtNetwork>

#include <cereal/archives/json.hpp>

#include "buffer.h"
#include "cli.h"
#include "db.h"
#include "filehandler.h"
#include "topwindow.h"
#include "packet.h"
#include "secrets/secrets.h"
#include "uploader.h"

static const std::string file_path = "input.bin";
static const uint32_t packet_size = 3136;

int main (int argc, char* argv[]) {
	QApplication a(argc, argv);

	if (!cli(argc, argv)) {
		// Watch our binary file for new packets to be parsed/stored.
		FileHandler f(file_path, packet_size);

        // Output the parsed data as JSON in the output window
		cereal::JSONOutputArchive archive(std::cout);
		f.add_output(archive);

        // Setup the database connection
		DB db("localhost", "cubesat");
		if (db.connect(secrets::username, secrets::password)) {
			qDebug() << "DB connected successfully.";
			f.add_output(db);
		} else {
			qWarning() << "DB failed to connect.";
		}

        // Setup the uploader
		Uploader uploader("http://localhost:8080", secrets::app_key);
		f.add_output(uploader);

		// Display the GUI.
        topwindow w;
		w.show();

		return a.exec();
	} else { return 0; }

	return a.exec();
}
