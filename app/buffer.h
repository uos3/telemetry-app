#ifndef BUFFER_H
#define BUFFER_H

#include <QDebug>

#include <fstream>
#include <memory>
#include <string.h>


class Buffer {
public:
	// Construction / Destruction
	Buffer();

	// Methods
	void from_file (std::string fname, uint64_t size=0);
	uint32_t get (uint32_t start_bit, size_t num_bits);
	uint32_t get (size_t num_bits);

	// Static Methods
	static float parse_float (uint8_t real);

	// Getters / Setters
	char* getBuf ();
	uint64_t getLen ();
	uint64_t getPos ();
	void setPos (uint64_t pos);
protected:
	std::unique_ptr<char[]> buf;
	uint64_t len;
	uint64_t pos = 0;
};

#endif // BUFFER_H
