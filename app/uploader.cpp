#include "uploader.h"

#include <QNetworkRequest>
#include <QUrlQuery>


Uploader::Uploader (std::string target, std::string app_key) :
	manager(new QNetworkAccessManager(this)),
	target(target),
	app_key(app_key) { }

void Uploader::upload (QByteArray data) {
	QString data_str(data.toBase64());
	qDebug() << data_str;

	QUrl url(QString::fromStdString(target));
	QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader,
	                  "application/x-www-form-urlencoded");

	QUrlQuery params;
	params.addQueryItem("app_key", QString::fromStdString(app_key));
	params.addQueryItem("data", data_str);

	connect(manager.get(), &QNetworkAccessManager::finished,
	        this, &Uploader::reply_finished);

	manager->post(request, params.query().toUtf8());
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
