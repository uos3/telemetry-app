#include "buffer.h"

#include <fstream>
#include <memory>


Buffer::Buffer (const char buf[], uint64_t len)
	: buf(buf), len(len) {}

Buffer::Buffer (std::unique_ptr<const char[]> buf, uint64_t len)
	: buf(std::move(buf)), len(len) {}

Buffer::Buffer (Buffer&& other)
	: buf(std::move(other.buf)), len(other.len) {}

Buffer& Buffer::operator= (Buffer&& other) {
	buf = std::move(other.buf);
	len = other.len;

	return *this;
}

Buffer::~Buffer () {}

Buffer Buffer::from_file (const std::string &filename, uint64_t size) {
	std::ifstream is (filename, std::ifstream::binary);
	if (!is)
		throw std::runtime_error(
			"couldn't read " + filename + " -- are you sure it exists?");

	is.seekg(0, is.end);
	uint64_t file_length = static_cast<uint64_t>(is.tellg());

	if (size > file_length)
		throw std::runtime_error("tried to read beyond end of file.");
	if (!size)
		size = file_length;

	is.seekg(-size, is.end);

	std::unique_ptr<char[]> data(new char[size]);
	is.read(data.get(), size);

	if (!is) {
		is.close();
		throw std::runtime_error("error reading file " + filename + ".");
	}

	is.close();

	return Buffer (std::move(data), size);
}

uint32_t Buffer::get (uint32_t start_bit, size_t num_bits) {
	/* TODO #documentation: re: throws */
	if (num_bits > 32)
		throw std::runtime_error("Buffer::get can only read up to 32 bits -- tried to "
		                         "read " + std::to_string(num_bits) + ".");

	if (start_bit + num_bits > len * 8)
		throw std::runtime_error("tried to read beyond end of buffer.");

	uint32_t byte = start_bit / 8;
	uint8_t  bit  = start_bit % 8;

	if (bit + num_bits > 8) {
		// want to read 'across' bytes, so must do in multiple stages.
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
