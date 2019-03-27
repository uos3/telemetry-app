#!/usr/bin/env python3

import sys
import json
import yaml # pip package PyYAML

import outputs

# TODO #finish:
#  * use actual (not c-based) sizes in yaml
#    X support non-c-based type sizes in parsing
#  * outputs:
#    X struct
#      * maybe have comments after each line, containing the desc for the field
#        if set?
#    X cereal (serialize function, & serialize function in struct)
#    X sql
#    X json & yaml
#    X std::map (including assigning the values from a buffer?)
#    X buffer parsing function
#    X db insert from struct function
#  * ability of specification files to be read by c++ (might involve using json
#    instead of yaml).
#    * from a brief look, it seems that parsing yaml from c++ needs an external
#      library (most likely yaml-cpp, which requires building) and isn't
#      supported by qt (whereas json is).
#    * sort of solved this issue -- yml2json.py converts yaml to json, so the
#      difference is meaningless from this file's perspective
#    * steps:
#       X let this program work with json (as well as yaml)
#       * rewrite db.cpp to iterate over the json
#    * issue: QJsonDocument has the members of a json object as unsorted (aka
#      sorted alphabetically), which obviously breaks this as the members of the
#      packet would get eg. parsed out of order. no way around that, apart from
#      making the spec use an array instead of an object for all the fields.
#      makes things kind of awkward though.
#  * be able to take in a header and/or footer with the -h & -f options

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

def header ():
    pass

def main ():
    # cli.
    if len(sys.argv) < 3:
        print('please supply an output type and yaml/json file(s) to parse.')
        print()
        print('accepted output types are: ', ''.join(k + '  ' for k in outputs.keys()))
        print()
        print('example usage:\n\t$ ./parser.py cereal_struct packet.yml status.json')
        return

    # try and find the function corresponding to the output type we were given.
    fn_name = sys.argv[1]
    fn = None
    if fn_name in outputs:
        fn = outputs[fn_name]
    else:
        print('unknown output type \'' + fn + '\'.\naccepted types are:',
              outputs)
        return

    # parse the file & print the output.
    for file in sys.argv[2:]:
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
        if fn_name in packet['name']:
            name = packet['name'][fn_name]
        elif fn_name in names and names[fn_name] in packet['name']:
            name = packet['name'][names[fn_name]]

        # parse the file, and print out the result to stdout
        print(fn(packet, name) + '\n')

if __name__ == '__main__':
    main()
