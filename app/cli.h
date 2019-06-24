#pragma once

#include <string.h>
#include "cereal/archives/json.hpp"
#include "buffer.h"
#include "packet.h"


// Note: this file intentionally uses no Qt, so that it can be compiled into a minimal
// CLI program (necessary because of storage constraints on the server).

/// \brief (Possibly) execute one of a number of functions that don't require a
///        GUI. If one of these functions runs, the GUI doesn't launch.
/// \returns Whether a commandline function was invoked (1) or not (0).
int cli (int argc, char *argv[]);

/// \brief Print parsed json of a packet to stdout.
void parse (char* fname);
