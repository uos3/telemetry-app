#ifndef DB_H
#define DB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <string.h>

#include "packet.h"

class DB {
public:
	// Construction / Destruction
	DB(std::string hostname,
	   std::string dbname,
	   std::string username,
	   std::string password);

	// Methods
	QSqlQuery get (QString table, QString field="*");
	static QList<QPair<QString, QString>> row (QSqlQuery qu, QString fields);
	QTableView* table (QString table, QString fields);
	bool store_packet (Packet p);

	// Getters / Setters
private:
	// Members
	QSqlDatabase db;

	// Methods
};

#endif // DB_H