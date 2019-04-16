#pragma once

#include "buffer.h"
#include "packet.h"

#include <QObject>


class Input : public QObject {
	Q_OBJECT

public:
	Input (QObject* parent) : QObject(parent) {}

signals:
	void new_packet (const Buffer& buffer, const Packet& packet);
};
