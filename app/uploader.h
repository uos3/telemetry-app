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
	Uploader(QString target = "http://localhost:8080");

	// Methods
	/// \brief Upload data in (string) key-value form to the/a server, via POST.
	/// \param body The list of (key, value) pairs to upload.
	void upload(std::vector<std::tuple<QString, QString>> body);

	/// \brief Upload data in byte array form to the/a server, via POST.
	void upload(QByteArray body);

	/// \brief Upload data in byte array form to the/a server, via POST.
	void upload(std::string api_key, QByteArray data);

	/// \brief Upload sample data in (string) key-value form to the (a) server,
	///        via POST.
	void upload();

	// Getters / Setters
	QString get_target();
	void set_target (QString target);

public slots:
	void reply_finished (QNetworkReply* reply);

private:
	// Members
	std::unique_ptr<QNetworkAccessManager> manager;
	std::unique_ptr<QHttpMultiPart> multiPart;
	QString target;
};
