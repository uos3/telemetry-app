#pragma once

#include <string.h>
#include <cereal/archives/json.hpp>
#include "buffer.h"
#include "packet.h"

/// \brief (Possibly) execute one of a number of functions that don't require a
///        GUI. If one of these functions runs, the GUI doesn't launch.
/// \returns Whether a commandline function was invoked (1) or not (0).
int cli (int argc, char *argv[]);

/// \brief Print parsed json of a packet to stdout.
void parse (char* fname);
