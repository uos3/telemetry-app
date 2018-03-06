#ifndef READER_H
#define READER_H

#include <fstream>
#include <string.h>
#include <QDebug>


class Reader {
public:
    Reader();
	void testing();
	uint8_t get(unsigned int idx);
};

#endif // READER_H