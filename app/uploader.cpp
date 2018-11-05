#include "uploader.h"

#include <QHttpPart>
#include <QNetworkRequest>
#include <QUrlQuery>


Uploader::Uploader (QString target) :
	manager(new QNetworkAccessManager(this)),
	multiPart(new QHttpMultiPart(QHttpMultiPart::FormDataType, this)),
	target(target) { }

void Uploader::upload (std::vector<std::tuple<QString, QString>> body) {
	QUrl url(target);
	QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader,
	                  "application/x-www-form-urlencoded");

	QUrlQuery params;
	for (auto item : body) {
		params.addQueryItem (std::get<0>(item), std::get<1>(item));
	}

	connect(manager.get(), &QNetworkAccessManager::finished,
	        this, &Uploader::reply_finished);

	manager->post(request, params.query().toUtf8());
}

void Uploader::upload (QByteArray body) {
	QUrl url(target);
	QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader,
	                  "application/x-www-form-urlencoded");

	connect(manager.get(), &QNetworkAccessManager::finished,
	        this, &Uploader::reply_finished);

	manager->post(request, body);
}

void Uploader::upload (std::string api_key, QByteArray data) {
	QHttpPart textPart;
	textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"api_key\""));
	textPart.setBody(api_key.c_str());

	QHttpPart binaryPart;
	binaryPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
	binaryPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"data\""));
	binaryPart.setBody(data);

	multiPart->append(textPart);
	multiPart->append(binaryPart);

	QUrl url(target);
	QNetworkRequest request(url);

	connect(manager.get(), &QNetworkAccessManager::finished,
	        this, &Uploader::reply_finished);

	manager->post(request, multiPart.get());
}

void Uploader::upload () {
	std::vector<std::tuple<QString, QString>> body;
	body.push_back(std::make_tuple("name", "seymour"));
	upload(body);
}

// Slots
void Uploader::reply_finished (QNetworkReply* reply) {
	QByteArray data = reply->readAll();
	reply->deleteLater();

	/* TODO #finish: something more intelligent than this.
	 *                * do I really need a slot here? could just leave it to
	 *                  clients to deal with replies as they will. */
	QString dataString = QString::fromUtf8(data);
	qDebug() << dataString;
}

// Getters / Setters
QString Uploader::get_target () { return this->target; }
void Uploader::set_target (QString target) { this->target = target; }
