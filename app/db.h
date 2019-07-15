#pragma once

#include "packet.h"

#include <QByteArray>
#include <QSqlDatabase>

namespace db {

/// \brief Stores a packet in the database.
/// \param p The packet to be stored.
/// \returns Whether or not the query to store the packet was successfully
///          executed.
bool store_packet (QSqlDatabase& db, const Packet& p, const QByteArray& binary);

}
