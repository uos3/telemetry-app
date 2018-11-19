#!/usr/bin/env python3

import sys
import json
import yaml # pip package PyYAML

# TODO:
#  * use actual (not c-based) sizes in yaml
#    X support non-c-based type sizes in parsing
#  * outputs:
#    X struct
#      * maybe have comments after each line, containing the desc for the field
#        if set?
#    X cereal (serialize function, & serialize function in struct)
#    X sql
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
#  * be able to take in a header and/or footer with the -h & -f options

def c_type (data):
    if type(data) == str:
        return data

    int_sizes = [ 8, 16, 32, 64 ]

    name = data['name']

    if data['name'] == 'int':
        # specify signedness.
        if not data['signed']:
            name = 'u' + name

        # get size -- smallest possible int that can contain the value.
        size = data['bits']
        for s in int_sizes:
            if s >= size:
                size = s
                break

        # add the extra bits.
        name = name + str(size) + '_t'
    elif data['name'] == 'time':
        name = 'uint32_t'
    elif data['name'] == 'binary':
        name = 'char'

    return name

def struct (data, name):
    def field (name, val):
        if 'struct' in val:
            val = val['struct']

        if name[0] in [ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ]:
            name = '_' + name

        # if this is an array, add the [N] bit after.
        if 'length' in val or val['type']['name'] == 'binary':
            # get the length of the array
            if 'length' in val:
                count = val['length']
            else:
                count = int(val['type']['bits']/8)
            # compensate for null-termination
            if val['type']['name'] in [ 'char', 'binary' ]:
                count += 1

            name += '[' + str(count) + ']'

        # put it all together.
        return '\t' + c_type(val['type']) + ' ' + name + ';\n'

    out = 'struct ' + name + ' {\n'

    for f in data['fields'].keys():
        out += field(f, data['fields'][f])
    if 'special' in data and 'struct' in data['special']:
        for f in data['special']['struct']:
            out += field(f, data['special']['struct'][f])

    out += '};'
    return out

def cereal (data, name, idt=False):
    # if we're outputting the function as part of a struct, need to indent
    # everything.
    t = '\t' * int(idt)

    # start the function.
    out  = t + 'template <class Archive>\n'
    out += t + 'void serialize (Archive& ar) {\n'
    out += t + '\tar(\n'

    # turn the fields into cereal macro invocations.
    fields = data['fields']
    for f in fields.keys():
        val = fields[f]

        # use the correct macro for cereal.
        macro = 'CEREAL_NVP('
        if 'length' in val:
            if val['type']['name'] == 'char':
                macro = 'STRING_NVP('
            else:
                macro = 'ARRAY_NVP('
        out += t + '\t' + macro + f + '),\n'

    # end -- get rid of the last comma.
    out = out[:-2] + ');\n' + t + '}'

    return out

def cereal_struct (data, name):
    # make a struct.
    out = struct(data, name)

    # get rid of the closing of the struct.
    out = '\n'.join(out.split('\n')[:-1])
    out += '\n\n'

    # add the cereal function, indented.
    out += cereal(data, name, True)

    # add the struct close back in.
    out += '\n};'
    return out

def sql_type (data):
    tinfo = data['type']
    tname = tinfo['name']

    name = tname

    if tname == 'int':
        bits = tinfo['bits']
        if bits <= 8:
            name = 'tinyint'
        elif bits <= 16:
            name = 'smallint'
        elif bits <= 32:
            name = 'int'
        elif bits <= 64:
            name = 'bigint'
        if tinfo['signed'] == False:
            name += ' unsigned'
    elif tname == 'bool':
        name = 'boolean'
    elif tname == 'char':
        if 'length' in data:
            name += '('+str(data['length'])+')'
    elif tname == 'float':
        name = 'decimal'
    elif tname == 'time':
        name = 'timestamp'
    elif tname == 'binary':
        name = 'varbinary('+str(int(tinfo['bits']/8))+')'

    return name

def sql (data, name):
    out = 'create table if not exists ' + name + ' (\n'

    def field (name, val):
        out = ''
        if 'sql' in val:
            val = val['sql']
        if 'length' in val and val['type']['name'] != 'char':
            # if we're dealing with an array, make N rows appended with _n
            for i in range(val['length']):
                name_n = name + '_' + str(i+1)
                out += '\t' + name_n + ' ' + sql_type(val) + ',\n'
        else:
            # otherwise, output the field as normal
            out +=  '\t' + name + ' ' + sql_type(val) + ',\n'

        # return the string for a single field
        return out

    if 'keys' in data:
        key_types = data['keys']
        if 'primary' in key_types:
            for k in key_types['primary']:
                out += '\t' + k['name'] + ' serial primary key,\n'
        if 'foreign' in key_types:
            for k in key_types['foreign']:
                # TODO #verify: always bigint unsigned?
                out += '\t' + k['name'] + ' bigint unsigned,\n'
        out += '\n'

    for f in data['fields'].keys():
        out += field(f, data['fields'][f])
    if 'special' in data and 'sql' in data['special']:
        for f in data['special']['sql']:
            out += field(f, data['special']['sql'][f])

    if 'keys' in data:
        if 'foreign' in data['keys']:
            out += '\n'
            for k in key_types['foreign']:
                out += '\tforeign key ' + k['name'] + ' references ' + k['table'] + '(' + k['name'] + '),\n'

    # chop off the last comma & add the closing paren.
    out = out[:-2] + '\n);'
    return out

outputs = [ 'struct', 'cereal', 'cereal_struct', 'sql' ]

def main ():
    # cli.
    if len(sys.argv) < 3:
        print('please supply an output type and yaml/json file(s) to parse.')
        print()
        print('accepted output types are: ', outputs)
        print()
        print('example usage:\n\t$ ./parser.py cereal_struct packet.yml status.json')
        return

    # try and find the function corresponding to the output type we were given.
    fn_name = sys.argv[1]
    fn = None
    if fn_name in outputs:
        try:
            fn = globals()[fn_name]
        except KeyError:
            print(fn, 'has no matching function -- outputs list needs fixing')
            return
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
        # lol
        elif fn_name == 'cereal_struct' and 'struct' in packet['name']:
            name = packet['name']['struct']

        # parse the file, and print out the result to stdout
        print(fn(packet, name) + '\n')

if __name__ == '__main__':
    main()
