#pragma once

#include "output.h"

#include <QSqlDatabase>


// for inserting new packets into the local database.
class DBOutput : public Output
{
	Q_OBJECT

public:
	DBOutput (QSqlDatabase& db, QObject* parent=nullptr);

protected:
	bool do_output (const Buffer& buffer, const Packet& packet) override;

private:
	QSqlDatabase& db;
};
