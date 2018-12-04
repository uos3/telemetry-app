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
            # compensate for null-termination.
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
