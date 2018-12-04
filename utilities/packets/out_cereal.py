from out_struct import struct

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

