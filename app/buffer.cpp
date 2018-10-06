#include "buffer.h"

Buffer::Buffer () : buf(nullptr), len(0) { }

// Gets raw file and stores latest packet into buffer. default size=0 means
// read the whole file, size!=0 means read last 'size' bytes.
void Buffer::from_file (std::string fname, uint64_t size) {
	if (!this->buf) {
		// if we've loaded something before, clear the old buffer to load again.
		this->buf.reset();
		this->len = 0;
	}

	std::ifstream is (fname, std::ifstream::binary);
	if (is) {
		is.seekg(0, is.end);
		uint64_t length = static_cast<uint64_t>(is.tellg()); // length of the whole file
		if (!size) {
			size = length;
		} else {
			// TODO #robustness: something better than this.
			Q_ASSERT_X(size/8 <= length,
			           "buffer::from_file",
			           "tried to read beyond end of file.");
			size /= 8;
		}
		is.seekg(length-size, is.beg);

		std::unique_ptr<char[]> buffer(new char[size]);

		is.read(buffer.get(), size);

		if (!is) {
			throw std::runtime_error("error reading file " + fname + ".");
		}
		is.close();

		buf.swap(buffer);
		this->len = size;
	} else {
		throw std::runtime_error("couldn't read " + fname + " -- are you sure it exists?");
	}
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

char* Buffer::get_buf () { return this->buf.get(); }
uint64_t Buffer::get_len () { return this->len; }
uint64_t Buffer::get_pos () { return this->pos; }
void Buffer::set_pos (uint64_t pos) { this->pos = pos; }
