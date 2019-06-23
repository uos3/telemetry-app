#include "output_db.h"


DBOutput::DBOutput (DB& db, QObject* parent)
	: Output(parent)
	, db(db) {}

void DBOutput::output (const Buffer& buffer, const Packet& packet) {
	QByteArray binary(buffer.get_buf(), buffer.get_len());

	if (!db.store_packet(packet, binary)) {
		qWarning("failed to store packet in db %s.", db.get_name().c_str());
	}
}
