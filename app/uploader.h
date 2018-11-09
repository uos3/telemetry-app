#pragma once

#include <QHttpMultiPart>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <memory>
#include <vector>
#include <tuple>


class Uploader : public QObject {
	Q_OBJECT
public:
	// Construction / Destruction
	Uploader(std::string target="http://localhost:8080",
	         std::string app_key="",
	         std::string submit_key="");

	// Methods
	/// \brief Upload data in byte array form to the/a server, via POST.
	void upload(const QByteArray& body, uint32_t downlink_time);

	void upload(const QByteArray& body);

	// Getters / Setters
	std::string get_target();
	void set_target (std::string target);
	void set_app_key (std::string app_key);
	void set_submit_key (std::string submit_key);

public slots:
	void reply_finished (QNetworkReply* reply);

private:
	// Members
	std::unique_ptr<QNetworkAccessManager> manager;
	std::unique_ptr<QHttpMultiPart> multi_part;

	std::string target;
	std::string app_key;
	std::string submit_key;
};
