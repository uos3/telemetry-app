#include "buffer.h"

Buffer::Buffer() { }

Buffer::~Buffer() { if (this->buf) { delete[] this->buf; } }

void Buffer::from_file (std::string fname) {
	std::ifstream is (fname, std::ifstream::binary);
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
		} else { qDebug() << "error: only " << is.gcount() << " could be read"; }
		is.close();

		this->buf = buffer;
		this->len = length;
	} else { qDebug() << "couldn't read file"; }
}

uint32_t Buffer::get(uint32_t start_bit, size_t num_bits) {
	uint32_t byte = start_bit / 8;
	uint8_t  bit  = start_bit % 8;

	if (bit + num_bits > 8) {
		// want to read 'across' bytes, so must do in multiple stages.
		// TODO @optimisation: make this iterative.
		uint8_t available = 8 - bit;
		uint32_t val = this->get(start_bit, available);
		val = val << (num_bits - available);
		val |= this->get(start_bit + available, num_bits - available);
		return val;
	} else {
		// TODO @bug: what if num_bits is too big for the shift in a uint8_t?
		uint8_t mask = ((1 << num_bits) - 1) << (8 - num_bits - bit);
		return (this->buf[byte] & mask) >> (8 - bit - num_bits);
	}
}

char* Buffer::getBuf() { return this->buf; }
uint64_t Buffer::getLen() { return this->len; }