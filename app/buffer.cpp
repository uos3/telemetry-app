#include "buffer.h"

#include <QFile>
#include <QString>

Buffer::Buffer () : buf() {}

Buffer::Buffer (const QByteArray& byte_array)
	: buf(byte_array) {}

Buffer::~Buffer () {}

void Buffer::from_file (std::string filename, uint64_t size) {
	QFile file(QString::fromStdString(filename));

	if (!file.exists())
		throw std::runtime_error("file " + filename + " doesn't exist.");

	if (!file.open(QIODevice::ReadOnly))
		throw std::runtime_error("couldn't open file " + filename + ".");

	if (size == 0)
		size = file.size();

	if (!file.seek(file.size() - size))
		throw std::runtime_error("couldn't seek back " + std::to_string(size) +
		                         "bytes into " + filename + ".");

	buf = file.read(size);
	pos = 0;
}

uint32_t Buffer::get (uint32_t start_bit, size_t num_bits) {
	/* TODO #documentation: re: throws */
	if (num_bits > 32)
		throw std::runtime_error("Buffer::get can only read up to 32 bits -- tried to "
		                         "read " + std::to_string(num_bits) + ".");

	if (start_bit + num_bits > buf.size () * 8)
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

const char* Buffer::get_buf () const { return this->buf.data(); }
uint64_t Buffer::get_len () const { return this->buf.size(); }
uint64_t Buffer::get_pos () const { return this->pos; }
void Buffer::set_pos (uint64_t pos) { this->pos = pos; }
