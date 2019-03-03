#pragma once

#include <string>

#include <cstdint>

namespace util {

/// \brief Gets the current time.
uint32_t now ();

/// \brief Converts an int32 unix timestamp into a string, formatted for
///        entry in a MySQL database as a timestamp.
/// \param tstamp The timestamp to convert.
/// \returns The formatted string.
std::string time_string (uint32_t tstamp);
}
