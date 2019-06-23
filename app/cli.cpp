#include "cli.h"
#include "spec.h"

int cli (int argc, char *argv[]) {
	if (argc >= 2) {
		if (!strcmp(argv[1], "parse")) {
			if (argc < 3) { std::cout << "parse needs a filename.\n"; }
			else { parse(argv[2]); }
		}
		else { std::cout << "unknown function '" << argv[1] << "'.\n"; }
		return 1;
	}
	return 0;
}

void parse (char* fname) {
	Buffer b;
	b.from_file(fname);

	Packet p;
	from_buffer(p, b);

	{
		cereal::JSONOutputArchive archive(std::cout);
		archive(CEREAL_NVP(p));
	}
}
