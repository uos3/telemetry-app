#include <QCoreApplication>
#include <QTcpSocket>

#include <chrono>
#include <string>
#include <thread>
using namespace std;


int main (int argc, char* argv[]) {

	QCoreApplication app(argc, argv);

	QTcpSocket socket;

	socket.connectToHost("localhost", 7890, QIODevice::WriteOnly);

	if (!socket.waitForConnected(3000)) {
		qCritical("couldn't connect to host -- error %i.", socket.error());
		return 1;
	}

	while (true) {
		string message = "cool beans";
		socket.write(message.c_str(), message.length() + 1);
		socket.flush();

		qDebug ("wrote %s.", message.c_str());

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return app.exec();
}
