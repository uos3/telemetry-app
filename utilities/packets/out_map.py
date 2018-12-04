from out_struct import c_type

# c types with equivalent Qt types
q_types = [
    'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
    'int8_t',  'int16_t',  'int32_t',  'int64_t',
    'float', 'bool', 'char'
]

def map_type (data):
    name = c_type(data)

    if name in q_types:
        name = 'Q' + name.title()

        if name[-2:] == '_T':
            name = name[:-2]

    return name

# bit sizes of the basic types allowed in the spec
type_sizes = {
    'float': 32,
    'char': 8,
    'bool': 8,
    'time': 32
}

def map_size (data):
    size = -1
    if 'bits' in data['type']:
        size = data['type']['bits']
    elif data['type']['name'] in type_sizes:
        size = type_sizes[data['type']['name']]

    if 'length' in data['type'] and size != -1:
        size *= data['type']['length']

    return size

# TODO #finish: deal with arrays, check that it works etc.
def out_map (data, name):
    def field (name, val):
        if 'map' in val:
            val = val['map']
        elif 'struct' in val:
            val = val['struct']

        start = '\t{ '
        name = '"'+name+'", '
        ftype = 'QVariant(static_cast<' + map_type(val['type']) + '>('
        val = 'buf.get(' + str(map_size(val)) + ')'
        end = ')) },\n'

        return start + name + ftype + val + end

    # initial declaration
    out = 'std::map<std::string, QVariant> ' + name + ' {\n'

    # go through each field
    for f in data['fields'].keys():
        out += field(f, data['fields'][f])
    if 'special' in data and 'map' in data['special']:
        for f in data['special']['map']:
            out += field(f, data['special']['map'][f])

    # get rid of final comma, end
    out = out[:-2] + '\n};'

    return out
