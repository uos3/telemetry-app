#include "cli.h"

int cli (int argc, char *argv[]) {
	if (argc >= 2) {
		if (!strcmp(argv[1], "parse")) { return parse(argv[2]); }
	}
	return 0;
}

int parse (char* fname) {
// print parsed json of a packet to stdout
	Buffer b;
	b.from_file(fname);

	Packet p;
	from_buffer(p, b);

	// TODO #behaviour: arrays are output as json objects -- would prob be better as json arrays
	cereal::JSONOutputArchive archive(std::cout);
	archive(CEREAL_NVP(p));

	return 0;
}
