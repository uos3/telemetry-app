#pragma once

#include <QDebug>

#include <fstream>
#include <memory>
#include <string.h>


class Buffer {
public:
	// Construction / Destruction
	Buffer();

	// Methods
	/// \brief Reads a buffer from a binary file.
	/// \param fname The name of the binary file to load.
	/// \param size The number of bytes to read, from the end of the file.
	///             size == 0 reads the whole file.
	void from_file (std::string fname, uint64_t size=0);

	/// \brief Reads a specified number of bits from the buffer, from any
	///        location.
	/// \param start_bit The bit to start reading from.
	/// \param num_bits The number of bits to read. Note: this must be <=32,
	///                 since the returned value is converted to a uint32_t.
	uint32_t get (uint32_t start_bit, size_t num_bits);

	/// \brief Reads a specified number of bits, starting from the current
	///        position in the buffer. -- useful for parsing a big packet.
	uint32_t get (size_t num_bits);

	// Getters / Setters
	char* get_buf ();
	uint64_t get_len ();
	uint64_t get_pos ();
	void set_pos (uint64_t pos);
protected:
	std::unique_ptr<char[]> buf;
	uint64_t len;
	uint64_t pos = 0;
};
