#include <stdio.h>
#include <string.h>

#define INPUT_FILE_LENGTH 4096

int main (int argc, char* argv[]) {
	if (argc < 3) { printf("please specify input & output filenames as arguments.\n"); return 1; }

	// setup
	FILE* inf;
	char in[INPUT_FILE_LENGTH];
	char* infname = argv[1];
	printf("input file: %s\n", infname);

	// read file
	inf = fopen(infname, "r");
	if (!inf) { printf("couldn't open input file %s!\n", infname); return 1; }
	fgets(in, INPUT_FILE_LENGTH, inf);
	fclose(inf);
	int in_len = strlen(in);
	printf("%s contains %i characters.\n\n", infname, in_len);

	// convert ascii 1/0 to actual bits
	int out_len = in_len/8;
	char out[out_len];
	memset(out, '\0', out_len);

	for (int i=0;i<out_len;i++) {
		for (int j=7;j>=0;j--) {
			if (in[8*i+j] - 48) {
				out[i] |= (0x80 >> j);
			}
		}
	}

	printf("result:\n");
	for (int i=0;i<out_len;i++) { printf("%c", out[i]); } printf("\n\n");

	// write output
	FILE* outf;
	char* outfname = argv[2];

	outf = fopen(outfname, "wb");
	if (!outf) { printf("couldn't open output file %s!\n", outfname); return 1; }
	for (int i=0;i<out_len;i++) { fputc(out[i], outf); }
	fclose(outf);
	printf("output binary written to %s.\n", outfname);

	return 0;
}