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
			qDebug() << buffer;
		} else { qDebug() << "error: only " << is.gcount() << " could be read"; }
		is.close();

		this->buf = buffer;
		this->len = length;
//		delete[] buffer;
	} else { qDebug() << "couldn't read file"; }
}

QString b8_to_str (uint8_t byte) {
	QString str = "";
	str += (byte & 0x80 ? '1' : '0');
	str += (byte & 0x40 ? '1' : '0');
	str += (byte & 0x20 ? '1' : '0');
	str += (byte & 0x10 ? '1' : '0');
	str += (byte & 0x08 ? '1' : '0');
	str += (byte & 0x04 ? '1' : '0');
	str += (byte & 0x02 ? '1' : '0');
	str += (byte & 0x01 ? '1' : '0');
	return str;
}

QString b32_to_str (uint32_t byte) {
	QString str = "";
	str += (byte & 0x8000 ? '1' : '0');
	str += (byte & 0x4000 ? '1' : '0');
	str += (byte & 0x2000 ? '1' : '0');
	str += (byte & 0x1000 ? '1' : '0');
	str += (byte & 0x0800 ? '1' : '0');
	str += (byte & 0x0400 ? '1' : '0');
	str += (byte & 0x0200 ? '1' : '0');
	str += (byte & 0x0100 ? '1' : '0');
	str += (byte & 0x0080 ? '1' : '0');
	str += (byte & 0x0040 ? '1' : '0');
	str += (byte & 0x0020 ? '1' : '0');
	str += (byte & 0x0010 ? '1' : '0');
	str += (byte & 0x0008 ? '1' : '0');
	str += (byte & 0x0004 ? '1' : '0');
	str += (byte & 0x0002 ? '1' : '0');
	str += (byte & 0x0001 ? '1' : '0');
	return str;
}

uint32_t Buffer::get(uint32_t start_bit, size_t num_bits) {
	uint32_t byte = start_bit / 8;
	uint8_t  bit  = start_bit % 8;
	qDebug() << "reading bits: start" << start_bit << "(" << byte << "+" << bit
	         << "), num bits" << num_bits;

	if (bit + num_bits > 8) {
		qDebug() << "\t" << bit << "+" << num_bits << "is too big!";
		// want to read 'across' bytes, so must do in multiple stages.
		uint8_t available = 8 - bit;
		uint32_t val = this->get(start_bit, available);
		val = val << (num_bits - available);
		qDebug() << "\tgoing again w/ start" << start_bit+available << ", num bits" << num_bits-available;
		val |= this->get(start_bit + available, num_bits - available);
		qDebug() << "\tfully appended:" << b32_to_str(val);
		return val;
	} else {
		qDebug() << "\t" << bit << "+" << num_bits << "is a good size!";
		// TODO @bug: what if num_bits is too big for the shift in a uint8_t?
		uint8_t mask = ((1 << num_bits) - 1) << ((8 - num_bits) - bit);
		uint32_t val = (this->buf[byte] & mask) >> (8 - bit - num_bits);

		// PRINTY STUFF //////////////////////////
		qDebug() << "\tapplying mask: " << b8_to_str(mask)
		         << "to" << b8_to_str (this->buf[byte]) << "->" <<
		            val << ":" <<
		            (char)val << ":" <<
		            b8_to_str(val);
		// END PRINTY STUFF //////////////////////

		return val;
	}
}

char* Buffer::getBuf() { return this->buf; }
uint64_t Buffer::getLen() { return this->len; }