#!/usr/bin/env python3

import sys
import yaml # pip package PyYAML

# TODO:
#  * use actual (not c-based) sizes in yaml
#    X support non-c-based type sizes in parsing
#  * outputs:
#    X struct
#      * maybe have comments after each line, containing the desc for the field
#        if set?
#    X cereal (serialize function, & serialize function in struct)
#    * sql
#  * ability of specification files to be read by c++ (might involve using json
#    instead of yaml).
#    * from a brief look, it seems that parsing yaml from c++ needs an external
#      library (most likely yaml-cpp, which requires building) and isn't
#      supported by qt (whereas json is).
#    * sort of solved this issue -- yml2json.py converts yaml to json, so the
#      difference is meaningless from this file's perspective
#  * be able to take in a header and/or footer with the -h & -f options

def c_type (yml):
    if type(yml) == str:
        return yml

    int_sizes = [ 8, 16, 32, 64 ]

    name = yml['name']

    if yml['name'] == 'int':
        # specify signedness.
        if not yml['signed']:
            name = 'u' + name

        # get size -- smallest possible int that can contain the value.
        size = yml['bits']
        for s in int_sizes:
            if s >= size:
                size = s
                break

        # add the extra bits.
        name = name + str(size) + '_t'
    elif yml['name'] == 'time':
        name = 'uint32_t'
    elif yml['name'] == 'binary':
        name = 'char'

    return name

def struct (yml, name):
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

    for f in yml['fields'].keys():
        out += field(f, yml['fields'][f])
    if 'special' in yml and 'struct' in yml['special']:
        for f in yml['special']['struct']:
            out += field(f, yml['special']['struct'][f])

    out += '};'
    return out

def cereal (yml, name, idt=False):
    # if we're outputting the function as part of a struct, need to indent
    # everything.
    t = '\t' * int(idt)

    # start the function.
    out  = t + 'template <class Archive>\n'
    out += t + 'void serialize (Archive& ar) {\n'
    out += t + '\tar(\n'

    # turn the fields into cereal macro invocations.
    fields = yml['fields']
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

def cereal_struct (yml, name):
    # make a struct.
    out = struct(yml, name)

    # get rid of the closing of the struct.
    out = '\n'.join(out.split('\n')[:-1])
    out += '\n\n'

    # add the cereal function, indented.
    out += cereal(yml, name, True)

    # add the struct close back in.
    out += '\n};'
    return out

def sql_type (yml):
    tinfo = yml['type']
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
        if 'length' in yml:
            name += '('+str(yml['length'])+')'
    elif tname == 'float':
        name = 'decimal'
    elif tname == 'time':
        name = 'timestamp'
    elif tname == 'binary':
        name = 'varbinary('+str(int(tinfo['bits']/8))+')'

    return name

def sql (yml, name):
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

    if 'keys' in yml:
        key_types = yml['keys']
        if 'primary' in key_types:
            for k in key_types['primary']:
                out += '\t' + k['name'] + ' serial primary key,\n'
        if 'foreign' in key_types:
            for k in key_types['foreign']:
                # TODO #verify: always bigint unsigned?
                out += '\t' + k['name'] + ' bigint unsigned,\n'
        out += '\n'

    for f in yml['fields'].keys():
        out += field(f, yml['fields'][f])
    if 'special' in yml and 'sql' in yml['special']:
        for f in yml['special']['sql']:
            out += field(f, yml['special']['sql'][f])

    if 'keys' in yml:
        if 'foreign' in yml['keys']:
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
        print('please supply an output type and yaml file(s) to parse.')
        print('note: the key name for a packet should match its file name, one',
              'packet per file.')
        print()
        print('accepted output types are: ', outputs)
        print()
        print('example usage:\n\t$ ./parser.py cereal_struct packet.yml status.yml')
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
        # read the yaml, and turn it into a dict
        with open(file, 'r') as stream:
            try:
                packet = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)
                return

        # get the name of the output structure, based on output type
        # default to the name of the file
        name = file[:-len('.yml')] # TODO: also support .yaml
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
