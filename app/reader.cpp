#include "reader.h"

Reader::Reader() { }

void Reader::testing () {
	std::ifstream is ("test.txt", std::ifstream::binary);
	if (is) {
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char* buffer = new char[length+1];

		qDebug() << "Reading " << length << " characters... ";

		is.read(buffer,length);

		if (is) {
			qDebug() << "all characters read successfully.\nbuffer:";
			buffer[length] = '\0';
			qDebug() << buffer;
		} else { qDebug() << "error: only " << is.gcount() << " could be read"; }
		is.close();
		delete[] buffer;
	} else { qDebug() << "couldn't read file"; }
}

uint8_t Reader::get(unsigned int idx) {

}