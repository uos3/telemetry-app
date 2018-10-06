#ifndef UPLOADER_H
#define UPLOADER_H

#include <vector>
#include <tuple>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>


class Uploader : public QObject {
	Q_OBJECT
public:
	// Construction / Destruction
	Uploader(QString target = "http://localhost:8080");

	// Methods
	void upload(std::vector<std::tuple<QString, QString>> body);
	void upload(QByteArray body);
	void upload();

	// Getters / Setters
	QString get_target();
	void set_target (QString target);

public slots:
	void reply_finished (QNetworkReply* reply);

private:
	// Members
	QNetworkAccessManager* manager;
	QString target;
};

#endif // UPLOADER_H
