#ifndef DB_H
#define DB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string.h>

class DB
{
public:
	// Construction / destruction
	DB(std::string hostname,
	   std::string dbname,
	   std::string username,
	   std::string password);

	// Methods
	QSqlQuery get (QString table, QString field="*");
	static QList<QPair<QString, QString>> row (QSqlQuery qu, QString fields);

	// Getters / setters
private:
	// Member variables
	QSqlDatabase db;

	// Methods
};

#endif // DB_H