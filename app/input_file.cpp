#include "input_file.h"

#include "utility.h"


FileInput::FileInput (const std::string& fname,
                      uint32_t packet_size,
                      QObject *parent)
	: Input(parent)
	, fname(fname)
	, packet_size(packet_size)
	, watcher(this) {
	watcher.addPath(QString::fromStdString(this->fname));

	connect(&watcher, &QFileSystemWatcher::fileChanged,
	        this, &FileInput::file_changed);
}

void FileInput::file_changed () {
	// NOTE: assumes that just one packet has been inserted in this update.
	Buffer buffer = Buffer::from_file(this->fname, this->packet_size);

	Packet packet;
	from_buffer(packet, buffer, util::now());

	emit new_packet(buffer, packet);
}
