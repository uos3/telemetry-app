#include <QByteArray>
#include <QCoreApplication>
#include <QFile>
#include <QTcpSocket>

#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
using namespace std;

const int wait_interval_seconds = 5;

const vector<string> binary_files =
	{ "config", "gps", "health", "img", "imu" };
const string binary_extension = "bin";
const string binary_directory = "../../packets";


string pickFile () {
	// setup for getting a random index into the list of file names
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(0, binary_files.size() - 1);

	// choose a filename at random
	string name = binary_files.at(uni(rng));

	// return a complete filename from a random file
	return binary_directory + "/" + name + "." + binary_extension;
}

QByteArray readFile (string filename) {
	QByteArray data;
	QFile file(QString::fromStdString(filename));

	if (!file.open(QIODevice::ReadOnly))
		return data;

	data = file.read(file.size());

	return data;
}

int main (int argc, char* argv[]) {

	QCoreApplication app(argc, argv);

	QTcpSocket socket;

	socket.connectToHost("localhost", 7890, QIODevice::WriteOnly);

	if (!socket.waitForConnected(3000)) {
		qCritical("couldn't connect to host -- error %i.", socket.error());
		if (socket.error() == 0)
			qCritical("you should start the telemetry app first.");
		return 1;
	}

	while (true) {
		auto name = pickFile();
		auto data = readFile(name);
		socket.write(data);

		socket.flush();

		qDebug ("%s: wrote %i bytes.", name.c_str(), data.size());

		this_thread::sleep_for(chrono::milliseconds(wait_interval_seconds * 1000));
	}

	return app.exec();
}
