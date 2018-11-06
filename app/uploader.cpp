#include "uploader.h"

#include <QHttpPart>
#include <QNetworkRequest>
#include <QUrlQuery>


Uploader::Uploader (std::string target, std::string app_key) :
	manager(new QNetworkAccessManager(this)),
	target(target),
	app_key(app_key) { }

void Uploader::upload (QByteArray data) {
	multiPart.reset(new QHttpMultiPart(QHttpMultiPart::FormDataType, this));

	QUrl url(QString::fromStdString(target));
	QNetworkRequest request(url);

	QHttpPart textPart;
	textPart.setHeader(QNetworkRequest::ContentDispositionHeader,
	                   QVariant("form-data; name=\"app_key\""));
	textPart.setBody(app_key.c_str());

	QHttpPart binaryPart;
	binaryPart.setHeader(QNetworkRequest::ContentTypeHeader,
	                     QVariant("application/octet-stream"));
	binaryPart.setHeader(QNetworkRequest::ContentDispositionHeader,
	                     QVariant("form-data; name=\"data\"; filename=\"data.bin\""));
	binaryPart.setBody(data);

	multiPart->append(textPart);
	multiPart->append(binaryPart);

	connect(manager.get(), &QNetworkAccessManager::finished,
	        this, &Uploader::reply_finished);

	manager->post(request, multiPart.get());
}

void Uploader::reply_finished (QNetworkReply* reply) {
	QByteArray data = reply->readAll();
	reply->deleteLater();

	/* TODO #finish: something more intelligent than this.
	 *                * do I really need a slot here? could just leave it to
	 *                  clients to deal with replies as they will. */
	QString dataString = QString::fromUtf8(data);
	qDebug() << dataString;
}

std::string Uploader::get_target () { return this->target; }
void Uploader::set_target (std::string target) { this->target = target; }
void Uploader::set_app_key (std::string app_key) { this->app_key = app_key; }
