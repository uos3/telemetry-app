#ifndef DB_H
#define DB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
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
//  eg. * class DB: public QSqlDatabase
//      * get rid of connect (but keep the constructor)
//      * get rid of the destructor, copy constructor and assignment operator
//        (since it's a QSqlDatabase, so we can just tell users to disconnect)
//      * get rid of table, probably -- should be in some kind of UI file
//        anyway.
//      * can get rid of row (I think, so long as the queries have properly
//        bound values).
//  downsides:
//      * is less of an abstraction of the database
//      * more flexible than is needed
//      * might be awkward to subclass QSqlDatabase
class DB {
public:
	// Construction / Destruction
	DB(std::string hostname, std::string dbname);
	DB(const DB& other);

	DB& operator=(const DB& other);

	~DB();

	// Methods
	/// \brief Attempts to connect to the database, with the supplied
	///        credentials.
	/// \returns the success of opening the connection.
	bool connect (std::string username, std::string password);

	/// \brief Selects fields from a table, and returns the executed QSqlQuery.
	QSqlQuery get (QString table, QString field="*");

	/// \brief Returns a tuple representation of the result of a SELECT
	///        QSqlQuery.
	/// \returns A list of (string, string) tuples corresponding to
	///          field_name: value
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
