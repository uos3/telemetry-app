#include "uploader.h"

#include "utility.h"

#include <QHttpPart>
#include <QNetworkRequest>
#include <QUrlQuery>


Uploader::Uploader (std::string target, std::string app_key,
                    std::string submit_key) :
	manager(new QNetworkAccessManager(this)),
	target(target),
	app_key(app_key),
	submit_key(submit_key) { }

void Uploader::upload (const QByteArray& data, uint32_t downlink_time) {
	multi_part.reset(new QHttpMultiPart(QHttpMultiPart::FormDataType, this));

	QUrl url(QString::fromStdString(target));
	QNetworkRequest request(url);

	QHttpPart app_key_part;
	app_key_part.setHeader(QNetworkRequest::ContentDispositionHeader,
	                   QVariant("form-data; name=\"app_key\""));
	app_key_part.setBody(app_key.c_str());

	QHttpPart submit_key_part;
	submit_key_part.setHeader(QNetworkRequest::ContentDispositionHeader,
	                   QVariant("form-data; name=\"submit_key\""));
	submit_key_part.setBody(submit_key.c_str());

	QHttpPart downlink_time_part;
	downlink_time_part.setHeader(QNetworkRequest::ContentDispositionHeader,
	                   QVariant("form-data; name=\"downlink_time\""));
	downlink_time_part.setBody(QString::number(downlink_time).toLatin1());

	QHttpPart binary_part;
	binary_part.setHeader(QNetworkRequest::ContentTypeHeader,
	                     QVariant("application/octet-stream"));
	binary_part.setHeader(QNetworkRequest::ContentDispositionHeader,
	                     QVariant("form-data; name=\"data\"; filename=\"data.bin\""));
	binary_part.setBody(data);

	multi_part->append(app_key_part);
	multi_part->append(submit_key_part);
	multi_part->append(downlink_time_part);
	multi_part->append(binary_part);

	connect(manager.get(), &QNetworkAccessManager::finished,
	        this, &Uploader::reply_finished);

	manager->post(request, multi_part.get());
}

void Uploader::upload (const QByteArray& data) {
	upload(data, util::now());
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
void Uploader::set_submit_key (std::string submit_key) { this->submit_key = submit_key; }
