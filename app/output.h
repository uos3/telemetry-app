#pragma once

#include "buffer.h"
#include "input.h"
#include "packet.h"

#include <QObject>


class Output : public QObject
{
	Q_OBJECT

public:
	Output (QObject* parent) : QObject(parent) {}

	void listen_to (const Input& input) {
		connect(&input, &Input::new_packet, this, &Output::output);
	}

signals:
	void packet_output (const Packet& packet);

public slots:
	void output (const Buffer& buffer, const Packet& packet) {
		if (do_output(buffer, packet))
			emit (packet_output(packet));
	}

protected:
	virtual bool do_output (const Buffer& buffer, const Packet& packet) = 0;
};
