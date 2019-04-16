#pragma once

#include "input.h"

#include <QFileSystemWatcher>

class FileInput : public Input {
	Q_OBJECT

public:
	explicit FileInput (const std::string& fname,
	                    uint32_t packet_size=0,
	                    QObject *parent=nullptr);

public slots:
	void file_changed ();

private:
	const std::string fname;
	const uint32_t packet_size;

	QFileSystemWatcher watcher;
};
