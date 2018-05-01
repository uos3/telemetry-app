#include "buffer.h"

Buffer::Buffer () { }

Buffer::~Buffer () { if (this->buf) { delete[] this->buf; } }

void Buffer::from_file (std::string fname, int packSize) {

	std::ifstream ifs (fname, std::ifstream::binary);
	if (ifs) {
		ifs.seekg(0, ifs.end);
		int fileLen = ifs.tellg();
		std::istream::get pack (ifs.seekg(0, ifs.end - packSize), packSize);
	}

	std::istream is (pack);
	if (is) {
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char* buffer = new char[length+1];

		qDebug() << "Reading " << length << " characters... ";
		is.read(buffer,length);

		if (is) {
			qDebug() << "all characters read successfully.";
			buffer[length] = '\0';
		} else { qDebug() << "error: only " << is.gcount() << " could be read"; }
		is.close();

		this->buf = buffer;
		this->len = length;
	} else { qDebug() << "couldn't read file"; }
}

uint32_t Buffer::get (uint32_t start_bit, size_t num_bits) {
	uint32_t byte = start_bit / 8;
	uint8_t  bit  = start_bit % 8;

	if (bit + num_bits > 8) {
		// want to read 'across' bytes, so must do in multiple stages.
		// TODO #optimisation: make this iterative.
		uint8_t available = 8 - bit;
		uint32_t val = this->get(start_bit, available);
		val = val << (num_bits - available);
		val |= this->get(start_bit + available, num_bits - available);
		return val;
	} else {
		uint8_t mask = ((1 << num_bits) - 1) << (8 - num_bits - bit);
		return (this->buf[byte] & mask) >> (8 - bit - num_bits);
	}
}

uint32_t Buffer::get (size_t num_bits) {
	uint32_t bits = get(pos, num_bits);
	pos += num_bits;
	return bits;
}

float Buffer::parse_float (uint8_t in) {
	// TODO #finish: find out what the actual format of the input reals are, and use that.
	std::string msg = "parse_float hasn't been implemented yet, as the format "
	"of the mini-reals is not finalised. For now, treat them as uints.";
	throw std::runtime_error(msg);

	// input format:  1bit sign, 1bit exp sign, 2bit exp, 4bit mantissa.
	// output format: 1bit sign, 8bit exponent, 23bit mantissa.
	float f = 0;

//	uint8_t sign     = (in & 0x80) >> 7;
//	uint8_t exp_sign = (in & 0x40) >> 6;
//	uint8_t exp      = (in & 0x30) >> 4;
//	uint8_t mantissa = (in & 0x0F);

	// TODO #check: verify shifts etc.
	uint32_t sign     = (in & 0x80) << 25;
	uint32_t exp_sign = (in & 0x40) << 24; // TODO #check: correct?
	uint32_t exp      = (in & 0x30) << 19;
	uint32_t mantissa = (in & 0x0F);

	f = (float)(sign & exp_sign & exp & mantissa);

	return f;
}

char* Buffer::getBuf () { return this->buf; }
uint64_t Buffer::getLen () { return this->len; }
uint64_t Buffer::getPos () { return this->pos; }
void Buffer::setPos (uint64_t pos) { this->pos = pos; }
