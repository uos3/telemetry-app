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
