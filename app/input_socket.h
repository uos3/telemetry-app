#pragma once

#include "input.h"

#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>

#include <memory>
#include <vector>


// helper class for each client of the main server socket, for receiving new data and
// emitting signals accordingly.
class SocketInputClient : public QObject {
	Q_OBJECT

public:
	explicit SocketInputClient (QTcpSocket* socket, QObject* parent=nullptr);

	QTcpSocket* get_socket ();

signals:
	void new_packet (const Buffer& buffer, const Packet& packet);

private slots:
	void new_data ();

private:
	QTcpSocket* socket;
};


// for receiving new packets via network messages.
class SocketInput : public Input {
	Q_OBJECT

public:
	explicit SocketInput (uint16_t port=7890,
	                      const std::string& hostname="localhost",
	                      QObject *parent=nullptr);

public slots:
	void new_client ();

private:
	QTcpServer socket;

	std::vector<SocketInputClient*> clients;
};
