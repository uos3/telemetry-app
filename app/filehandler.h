#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QFileSystemWatcher>
#include <QObject>

#include "buffer.h"
#include "db.h"
#include "packet.h"

class FileHandler : public QObject
{
	Q_OBJECT
public:
	explicit FileHandler (const std::string fname,
	                      const uint32_t packet_size=0,
	                      DB* db=nullptr,
	                      QObject *parent = nullptr);

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

	// TODO #enchancement: make this some kind of smart pointer? -- I don't
	//                     think we want to have the power to delete the
	//                     underlying DB though, just to know if it's been
	//                     deleted.
	DB* db;
	// TODO #enhancement: add an optional cereal output archive?
};

#endif // FILEHANDLER_H
