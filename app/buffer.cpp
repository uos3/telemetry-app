#include "buffer.h"

Buffer::Buffer () : buf(nullptr), len(0) { }

Buffer::Buffer (QByteArray& byte_array)
	: buf(byte_array.data())
	, len(byte_array.length()) { }

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
			// TODO #robustness
			if (size/8 > length) {
				is.close();
				throw std::runtime_error("tried to read beyond end of file.");
			}
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
	// TODO #robustness: some check that num_bits <= 32 (how to deal with
	//                   failure?)
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

const char* Buffer::get_buf () const { return this->buf.get(); }
uint64_t Buffer::get_len () const { return this->len; }
uint64_t Buffer::get_pos () const { return this->pos; }
void Buffer::set_pos (uint64_t pos) { this->pos = pos; }
