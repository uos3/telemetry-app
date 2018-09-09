#ifndef CLI_H
#define CLI_H

#include <string.h>
#include <cereal/archives/json.hpp>
#include "buffer.h"
#include "packet.h"

int cli (int argc, char *argv[]);

void parse (char* fname);

#endif // CLI_H
