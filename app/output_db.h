#pragma once

#include "db.h"
#include "output.h"


// for inserting new packets into the local database.
class DBOutput : public Output
{
	Q_OBJECT

public:
	DBOutput (DB& db, QObject* parent=nullptr);

public slots:
	void output (const Buffer& buffer, const Packet& packet) override;

private:
	DB& db;
};
