# packet-parser

A small CLI program for parsing packets from the satellite, and spitting them
out as json.

## Dependencies

* [cereal (1.2.2)](https://uscilab.github.io/cereal) (included in `app/cereal`)
* gcc

## Installation

```bash
$ git clone https://github.com/uos3/telemetry-app.git
$ cd telemetry-app/utilities/parser
$ make
```

## Usage

### `parse`

Takes a filename (the binary). Returns the json of the packet to stdout.

Example:

```bash
$ ./parser parse gps.bin
# json follows
```
