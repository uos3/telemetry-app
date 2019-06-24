#include "cli.h"


// Note: this file intentionally uses no Qt, so that it can be compiled into a minimal
// CLI program (necessary because of storage constraints on the server).

int main (int argc, char* argv[]) {
	if (!cli(argc, argv)) {
		std::cout
			<< "usage:\n"
			<< "\tparse fname\tparse the binary file in argument 1, and output its packet\n"
			<< "\t\t\tjson to stdout.\n";
		return 1;
	}
	return 0;
}
