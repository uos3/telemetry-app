#ifndef DB_H
#define DB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QTextStream>
#include <string>

#include "packet.h"

// TODO #enhancement: make this a QThread (or perhaps a QRunnable, dispatching
//                    from a QThreadPool on query)
// TODO #enhancement: probably better to make this a subclass of QSqlDatabase,
//                    use QSqlQueries properly (eg. binding values and such),
//                    and getting rid of a few of the methods here (all public
//                    except store_packet?).
class DB {
public:
	// Construction / Destruction
	DB(std::string hostname, std::string dbname);
	DB(const DB& other);

	DB& operator=(const DB& other);

	~DB();

	// Methods
	bool connect (std::string username, std::string password);
	QSqlQuery get (QString table, QString field="*");
	static QList<QPair<QString, QString>> row (QSqlQuery qu, QString fields);
	// TODO #refactor: this sort of code should be in a UI class (once those are
	//                 in), to separate view from model.
	QTableView* table (QString table, QString fields);

	/// \brief Stores a packet in the database.
	/// \param p The packet to be stored.
	/// \returns Whether or not the query to store the packet was successfully
	///          executed.
	bool store_packet (Packet& p);

	// Getters / Setters
	std::string get_name ();
	std::string get_hostname ();
private:
	// Members
	QSqlDatabase db;
	std::string dbname;
	std::string hostname;

	// Methods
	/// \brief Converts an int32 unix timestamp into a string, formatted for
	///        entry in a MySQL database as a timestamp.
	/// \param tstamp The timestamp to convert.
	/// \returns The formatted string.
	QString time_string (uint32_t tstamp);
};

#endif // DB_H
