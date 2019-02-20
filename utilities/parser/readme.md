# packet-parser

A small CLI program for parsing packets from the satellite, and spitting them
out as json.

## Dependencies

* [cereal (1.2.2)](https://uscilab.github.io/cereal) (included in `src/cereal`)
* gcc

## Installation

```bash
$ git clone https://github.com/uos3/packet-parser.git
$ cd packet-parser
$ make
```

## Usage

### `parse`

Takes a filename (the binary). Returns the json of the packet to stdout.

Example:

```bash
$ ./parser parse dummy/gps.bin
# json follows
```
