#ifndef BUFFER_H
#define BUFFER_H

#include <fstream>
#include <string.h>
#include <QDebug>


class Buffer {
public:
    // Construction / Destruction
    Buffer();
    ~Buffer();
	// TODO @completeness: custom copy constructor, assignment operator.

	// Methods
	void from_file (std::string fname);
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
	// TODO @refactor: use a QByteArray?
	char* buf;
	uint64_t len;
	uint64_t pos = 0;
};

#endif // BUFFER_H