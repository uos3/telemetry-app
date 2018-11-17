#!/usr/bin/env python3

import sys
import yaml # pip package PyYAML

# TODO:
#  * use actual (not c-based) sizes in yaml
#    X support non-c-based type sizes in parsing
#  * outputs:
#    X struct
#    X cereal (serialize function, & serialize function in struct)
#    * sql
#  * ability of specification files to be read by c++ (might involve using json
#    instead of yaml).
#    * from a brief look, it seems that parsing yaml from c++ needs an external
#      library (most likely yaml-cpp, which requires building) and isn't
#      supported by qt (whereas json is).
#    * sort of solved this issue -- yml2json.py converts yaml to json, so the
#      difference is meaningless from this file's perspective

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

    return name

def struct (yml, name):
    struct_name = name[0].upper() + name[1:]
    final = 'struct ' + struct_name + ' {\n'

    fields = yml[name]
    for f in fields.keys():
        val = fields[f]

        # basic name -- c++ doesn't allow names starting with numerals
        f_name = f
        if f_name[0] in [ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ]:
            f_name = '_' + f_name

        # if this is an array, add the [N] bit after
        is_array = 'length' in val
        if is_array:
            f_name += '[' + str(val['length']) + ']'

        # put it all together
        final += '\t' + c_type(val['type']) + ' ' + f_name + ';\n'

    final += '};'
    return final

def cereal (yml, name, idt=False):
    # if we're outputting the function as part of a struct, need to indent
    # everything.
    t = '\t' * int(idt)

    # start the function.
    final  = t + 'template <class Archive>\n'
    final += t + 'void serialize (Archive& ar) {\n'
    final += t + '\tar(\n'

    # turn the fields into cereal macro invocations.
    fields = yml[name]
    for f in fields.keys():
        val = fields[f]

        # use the correct macro for cereal.
        macro = 'CEREAL_NVP('
        if 'length' in val:
            if val['type']['name'] == 'char':
                macro = 'STRING_NVP('
            else:
                macro = 'ARRAY_NVP('
        final += t + '\t' + macro + f + ')\n'

    # end -- get rid of the last comma.
    final = final[:-1] + ');\n' + t + '}'

    return final

def cereal_struct (yml, name):
    # make a struct.
    final = struct(yml, name)

    # get rid of the closing of the struct.
    final = '\n'.join(final.split('\n')[:-1])
    final += '\n\n'

    # add the cereal function, indented.
    final += cereal(yml, name, True)

    return final

outputs = [ 'struct', 'cereal', 'cereal_struct' ]

def main ():
    # cli.
    if len(sys.argv) < 3:
        print('please supply an output type and yaml file(s) to parse.')
        print('note: your top-level key names should match their file names.')
        print()
        print('accepted output types are: ', outputs)
        print()
        print('example usage:\n\t$ ./parser.py cereal_struct packet.yml status.yml')
        return

    # try and find the function corresponding to the output type we were given.
    fn = sys.argv[1]
    if fn in outputs:
        try:
            fn = globals()[fn]
        except KeyError:
            print(fn, 'has no matching function -- outputs list needs fixing')
            return
    else:
        print('unknown output type \'' + fn + '\'.\naccepted types are:',
              outputs)
        return

    # parse the file & print the output.
    for file in sys.argv[2:]:
        # get the name of the top-level key, which should match that of the file
        name = file[:-len('.yml')] # TODO: also support .yaml

        with open(file, 'r') as stream:
            try:
                packet = yaml.load(stream)
            except yaml.YAMLError as exc:
                print(exc)
                return
        print(fn(packet, name) + '\n')

if __name__ == '__main__':
    main()
