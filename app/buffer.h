#pragma once

#include <memory>


// Note: this class intentionally uses no Qt, so that it can be compiled into a minimal
// CLI program (necessary because of storage constraints on the server).

class Buffer {
public:
	// Construction / Destruction
	Buffer (const char buf[], uint64_t len);

	Buffer (std::unique_ptr<const char[]> buf, uint64_t len);

	Buffer (Buffer&& other);

	Buffer& operator= (Buffer&& other);

	~Buffer ();

	// Methods
	/// \brief Factory, to read a buffer from a binary file.
	/// \param fname The name of the binary file to load.
	/// \param size The number of bytes to read, from the end of the file.
	///             size == 0 reads the whole file.
	/// \returns The constructed buffer.
	static Buffer from_file (const std::string &filename, uint64_t size=0);

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
	const char* get_buf () const;
	uint64_t get_len () const;
	uint64_t get_pos () const;
	void set_pos (uint64_t pos);
private:
	// data.
	std::unique_ptr<const char[]> buf;

	// length of data in bytes.
	uint64_t len;

	// current position through the buffer in bits.
	uint64_t pos = 0;
};
