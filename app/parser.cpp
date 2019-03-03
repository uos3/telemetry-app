#include "cli.h"


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
