#include "db.h"

DB::DB(std::string hostname, std::string dbname, std::string username, std::string password) {
// set up db
	// 'QMYSQL driver not loaded' -> https://stackoverflow.com/a/47334605
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(QString::fromStdString(hostname));
	db.setDatabaseName(QString::fromStdString(dbname));
	db.setUserName(QString::fromStdString(username));
	db.setPassword(QString::fromStdString(password));
	if (db.open()) {
		qDebug("db opened successfully.");
	} else {
		qDebug("db failed to open.");
	}
}

QSqlQuery DB::get (QString table, QString field) {
	QSqlQuery query;
	if (query.exec("select " + field + " from " + table)) {
		return query;
	} else {
		// TODO - can prob deal with this better.
		std::string msg = "error with db query \"" + field.toStdString()+ "\".";
		throw std::runtime_error(msg);
	}
}