#include "cli.h"

int cli (int argc, char *argv[]) {
	if (argc >= 2) {
		if (!strcmp(argv[1], "parse")) { parse(argv[2]); }
		return 1; // 1 = cli used, 0 = cli not used.
	}
	return 0;
}

void parse (char* fname) {
// print parsed json of a packet to stdout
	Buffer b;
	b.from_file(fname);

	Packet p;
	from_buffer(p, b);

	// TODO #behaviour: arrays are output as json objects -- would prob be better as json arrays
	cereal::JSONOutputArchive archive(std::cout);
	archive(CEREAL_NVP(p));
}
