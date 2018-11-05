#include "filehandler.h"

#include <QByteArray>

FileHandler::FileHandler (const std::string fname,
                          const uint32_t packet_size,
                          QObject *parent) :
QObject(parent), fname(fname), packet_size(packet_size), watcher(this),
buffer(), packet() {
	watcher.addPath(QString::fromStdString(this->fname));

	connect(&watcher, &QFileSystemWatcher::fileChanged,
	        this, &FileHandler::file_changed);
}

void FileHandler::add_output (DB& db) {
	out_dbs.push_back(&db);
}

void FileHandler::add_output (cereal::JSONOutputArchive& json) {
	out_json.push_back(&json);
}

void FileHandler::add_output (Uploader& uploader) {
	out_uploaders.push_back(&uploader);
}

void FileHandler::file_changed () {
	qDebug("FileHandler: file %s changed.", fname.c_str());
	buffer.from_file(this->fname, this->packet_size);
	from_buffer(packet, buffer);

	// TODO #fix: currently this is a little broken -- running in qt creator
	//            will result in things not outputting until the program exits,
	//            and running from the terminal will result in the last line not
	//            printing until either file_changed is called or the program
	//            exits. not critical functionality, though.
	for (auto oj : this->out_json) {
		if (oj == nullptr) {
			qDebug("json output archive is null."); continue;
		}
		(*oj)(CEREAL_NVP(packet));
	}

	QByteArray binary(buffer.get_buf(), buffer.get_len());
	for (auto od : this->out_dbs) {
		if (!od->store_packet(packet, binary)) {
			qDebug("failed to store packet in db %s @ %s.",
			       od->get_name().c_str(),
			       od->get_hostname().c_str());
		}
	}

	for (auto ou : this->out_uploaders) {
		/* ou->upload(binary); */

		/* std::vector<std::tuple<QString, QString>> body; */
		/* body.push_back(std::make_tuple("api_key", ";)")); */
		/* body.push_back(std::make_tuple("data", QString(binary))); */
		/* ou->upload(body); */

		ou->upload(";)", binary);
	}

	emit new_packet(packet);
}