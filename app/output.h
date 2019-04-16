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

public slots:
	virtual void output (const Buffer& buffer, const Packet& packet) = 0;
};
