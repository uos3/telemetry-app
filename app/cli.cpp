#include "cli.h"

int cli (int argc, char *argv[]) {
	if (argc >= 2) {
		if (!strcmp(argv[1], "parse")) { parse(argv[2]); }
		return 1;
	}
	return 0;
}

void parse (char* fname) {
	Buffer b;
	b.from_file(fname);

	Packet p;
	from_buffer(p, b);

	cereal::JSONOutputArchive archive(std::cout);
	archive(CEREAL_NVP(p));
}
