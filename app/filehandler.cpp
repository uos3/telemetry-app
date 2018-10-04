#include "filehandler.h"
#include <cereal/archives/json.hpp>

FileHandler::FileHandler (const std::string fname,
                          const uint32_t packet_size,
                          DB* db,
                          QObject *parent) :
QObject(parent), fname(fname), packet_size(packet_size), watcher(this),
buffer(), packet(), db(db) {
	watcher.addPath(QString::fromStdString(this->fname));

	file_changed();

	connect(&watcher, &QFileSystemWatcher::fileChanged,
	        this, &FileHandler::file_changed);
}

void FileHandler::file_changed () {
	qDebug("FileHandler: file %s changed.", fname.c_str());
	buffer.from_file(this->fname, this->packet_size);
	from_buffer(packet, buffer);

	// TODO #temp
	cereal::JSONOutputArchive archive(std::cout);
	archive(CEREAL_NVP(packet));

	if (this->db != nullptr) {
		if (this->db->store_packet(packet)) {
			qDebug("packet stored in db.");
		}
		qDebug("failed to store packet in db.");
	} else {
		qDebug("no db!");
	}

	emit new_packet(packet);
}