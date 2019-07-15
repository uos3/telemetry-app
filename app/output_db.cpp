#include "output_db.h"

#include "db.h"


DBOutput::DBOutput (QSqlDatabase& db, QObject* parent)
	: Output(parent)
	, db(db) {}

bool DBOutput::do_output (const Buffer& buffer, const Packet& packet) {
	if (!db.isOpen())
		return false;

	QByteArray binary(buffer.get_buf(), buffer.get_len());

	if (!db::store_packet(db, packet, binary)) {
		qWarning("failed to store packet in db %s.", qPrintable(db.databaseName()));
		return false;
	}

	return true;
}
