#!/usr/bin/env python3

import argparse
import json
import sys
import yaml # pip package PyYAML

import outputs


outputs = {
    'struct': outputs.struct,
    'cereal': outputs.cereal,
    'cereal_struct': outputs.cereal_struct,
    'db_insert': outputs.db_insert,
    'map':    outputs.stdmap,
    'parse_buffer': outputs.parse_buffer,
    'sql':    outputs.sql,
    'json':   outputs.json,
    'yaml':   outputs.yaml
}

# which yaml name field should we use for this output type (if not the exact
# name of the output type)?
names = {
    'cereal': 'cpp',
    'db_insert': 'cpp',
    'map': 'cpp',
    'parse_buffer': 'cpp',
    'struct': 'cpp'
}

def cli ():
    ''' parse commandline arguments, and return an object containing their
    contents.
    '''

    args = argparse.ArgumentParser(conflict_handler='resolve',
        description='Generate various files from a json/yaml packet spec, and '
                    'output them to stdout.')

    args.add_argument('input_file', type=str, nargs='+',
                      help='Input packet spec file(s).')
    args.add_argument('--output', '-o', choices=outputs, required=True,
                      help='Type of output format to generate.')
    args.add_argument('--header', '-h',
                      help='Filename of a header, to prepend to the output.')
    args.add_argument('--footer', '-f',
                      help='Filename of a footer, to append to the output.')

    return args.parse_args()

def main ():
    # cli.
    args = cli()

    # find the function corresponding to the output type we were given.
    fn = outputs[args.output]

    if args.header is not None:
        print(open(args.header).read())

    # parse the file & print the output.
    for file in args.input_file:
        # get the name and extension from the filename
        dot_pos = len(file) - file[::-1].index('.')
        ext = file[dot_pos:]

        # choose the right type of basic parser for the file
        if ext in [ 'yml', 'yaml' ]:
            loader = yaml
            loader_error = json.JSONDecodeError
        elif ext == 'json':
            loader = json
            loader_error = yaml.YAMLError
        else:
            print('unknown filetype for', file)
            continue

        # read the yaml, and turn it into a dict
        with open(file, 'r') as stream:
            try:
                packet = loader.load(stream)
            except loader_error as exc:
                print(exc)
                continue

        # get the name of the output structure, based on output type
        # default to the name of the file
        name = file[:-(len(ext)+1)]
        # otherwise get output appropriate name, if applicable
        if args.output in packet['name']:
            name = packet['name'][args.output]
        elif args.output in names and names[args.output] in packet['name']:
            name = packet['name'][names[args.output]]

        # parse the file, and print out the result to stdout
        print(fn(packet, name) + '\n')

    if args.footer is not None:
        print(open(args.footer).read())

if __name__ == '__main__':
    main()
