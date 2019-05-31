# utilities

A collection of miscellanious utilities to help with the main application

## txt2bin

A small C program to take in a file containing binary written as plaintext 1s
and 0s, and turn it into an actual binary file.

### building

```bash
$ gcc -o txt2bin txt2bin.c
```

### example usage

```bash
$ ./txt2bin my_binary_text_file.txt my_actual_binary_file.bin
```

## packets

Utilities that allow you to only have to deal with the packet specification in
one place, in yaml files.

## json2bin

Tool to generate a dummy binary file for testing purposes, using the yaml spec files as pattern and JSON file with values as input.

### requirements

Requires `yml` and `bitstring` libraries. Install required packages from the `requirements.txt` file using pip:

```bash
$ pip install -r requirements.txt
```

### usage

Generates two files, the binary file and its text representation for visual control. 

```
usage: json2bin.py [-h] [-p PACKET_SPEC_FILENAME] [-s STATUS_SPEC_FILENAME]
                   {config,gps,health,img,imu} json_filename

Generate a binfile from JSON input.

positional arguments:
  {config,gps,health,img,imu}
                        type of packet to generate
  json_filename         file with input values

optional arguments:
  -h, --help            show this help message and exit
  -p PACKET_SPEC_FILENAME, --packet_spec PACKET_SPEC_FILENAME
                        packet specification yml file
  -s STATUS_SPEC_FILENAME, --status_spec STATUS_SPEC_FILENAME
                        status data specification yml file
```
