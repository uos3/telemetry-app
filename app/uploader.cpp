#include "uploader.h"

Uploader::Uploader (QString target) :
	manager(new QNetworkAccessManager(this)),
	target(target) { }

void Uploader::upload (std::vector<std::tuple<QString, QString>> body) {
// upload data in (string) key-value form to the (a) server, via POST
	QUrl url(target);
	QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader,
					  "application/x-www-form-urlencoded");

	QUrlQuery params;
	for (auto item : body) {
		params.addQueryItem (std::get<0>(item), std::get<1>(item));
	}

	QObject::connect(manager, &QNetworkAccessManager::finished,
	                 this, &Uploader::reply_finished);

	manager->post(request, params.query().toUtf8());
}

void Uploader::upload (QByteArray body) {
// upload data in byte array form to the (a) server, via POST
	// TODO: can't really test this properly until I have a sample packet in
	//       byte-array form to send.
	QUrl url(target);
	QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader,
					  "application/x-www-form-urlencoded");

	QObject::connect(manager, &QNetworkAccessManager::finished,
	                 this, &Uploader::reply_finished);

	manager->post(request, body);
}

void Uploader::upload () {
// upload sample data in (string) key-value form to the (a) server, via POST
	std::vector<std::tuple<QString, QString>> body;
	body.push_back(std::make_tuple("name", "seymour"));
	upload(body);
}

// Slots
void Uploader::reply_finished (QNetworkReply* reply) {
	QByteArray data = reply->readAll();
	reply->deleteLater();

	QString dataString = QString::fromUtf8(data);
	qDebug() << dataString;
}

// Getters / Setters
QString Uploader::get_target () { return this->target; }
void Uploader::set_target (QString target) { this->target = target; }
