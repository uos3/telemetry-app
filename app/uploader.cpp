#include "uploader.h"

#include "utility.h"

#include <QHttpPart>
#include <QNetworkRequest>
#include <QUrlQuery>

#include <string>


Uploader::Uploader (std::string address, uint16_t port, std::string app_key,
                    std::string submit_key) :
	manager(new QNetworkAccessManager(this)),
	address(address),
	port(port),
	app_key(app_key),
	submit_key(submit_key) { }

void Uploader::upload (const QByteArray& data, uint32_t downlink_time) {
	multi_part.reset(new QHttpMultiPart(QHttpMultiPart::FormDataType, this));

	QUrl url(QString::fromStdString(get_target()));
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
	if (!dataString.isEmpty()) {
		qDebug() << dataString;
	}
}

std::string Uploader::get_target () { return address + ':' + std::to_string(port); }
void Uploader::set_target (std::string target) {
	std::string addr = target.substr(0, target.find(':'));
	std::string port_str = target.substr(target.find(':') + 1);
	unsigned long port_long = 0;

	try {
		port_long = std::stoul(port_str);
	} catch (std::invalid_argument& e) {
		qCritical("port '%s' passed to Uploader::set_target was invalid.",
		          port_str.c_str());
		return;
	} catch (std::out_of_range& e) {
		qCritical("port '%s' passed to Uploader::set_target was out of range.",
		          port_str.c_str());
		return;
	}

	if (port_long > 65535) {
		qCritical("port '%s' passed to Uploader::set_target was out of range.",
		          port_str.c_str());
		return;
	}

	address = addr;
	port = static_cast<uint16_t>(port_long);
}
std::string Uploader::get_address () { return this->address; }
void Uploader::set_address (std::string address) { this->address = address; }
uint16_t Uploader::get_port () { return this->port; }
void Uploader::set_port (uint16_t port) { this->port = port; }
std::string Uploader::get_app_key () { return this->app_key; }
void Uploader::set_app_key (std::string app_key) { this->app_key = app_key; }
std::string Uploader::get_submit_key () { return this->submit_key; }
void Uploader::set_submit_key (std::string submit_key) { this->submit_key = submit_key; }
