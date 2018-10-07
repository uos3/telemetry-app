#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QFileSystemWatcher>
#include <QObject>

#include <cereal/archives/json.hpp>

#include "buffer.h"
#include "db.h"
#include "packet.h"

class FileHandler : public QObject
{
	Q_OBJECT
public:
	explicit FileHandler (const std::string fname,
	                      const uint32_t packet_size=0,
	                      QObject *parent = nullptr);

	void add_output (DB& db);

	void add_output (cereal::JSONOutputArchive& json);

signals:
	void new_packet (Packet packet);

public slots:
	void file_changed ();

private:
	const std::string fname;
	const uint32_t packet_size;

	QFileSystemWatcher watcher;
	Buffer buffer;
	Packet packet;

	std::vector<DB*> out_dbs;
	std::vector<cereal::JSONOutputArchive*> out_json;
};

#endif // FILEHANDLER_H
