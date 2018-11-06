#pragma once

#include <QFileSystemWatcher>
#include <QObject>
#include <QDebug>

#include <cereal/archives/json.hpp>

#include "buffer.h"
#include "db.h"
#include "packet.h"
#include "uploader.h"

class FileHandler : public QObject
{
	Q_OBJECT
public:
	explicit FileHandler (const std::string fname,
	                      const uint32_t packet_size=0,
	                      QObject *parent = nullptr);

	/// \brief Adds a database to the list of things to output newly parsed
	///        packets into.
	void add_output (DB& db);

	/// \brief Adds a json output archive to the list of things to output newly
	///        parsed packets into.
	void add_output (cereal::JSONOutputArchive& json);

	/// \brief Adds an upload target to the list of things to output newly
	///        parsed packets into.
	void add_output (Uploader& uploader);

signals:
	/// \brief A new packet has been parsed.
	void new_packet (Packet packet);

public slots:
	/// \brief The binary file containing packets has been changed (ie. a new
	///        packet has been inserted) -- parses, then passes the Packet to
	///        all the added outputs.
	void file_changed ();

private:
	const std::string fname;
	const uint32_t packet_size;

	QFileSystemWatcher watcher;
	Buffer buffer;
	Packet packet;

	std::vector<DB*> out_dbs;
	std::vector<cereal::JSONOutputArchive*> out_json;
	std::vector<Uploader*> out_uploaders;
};
