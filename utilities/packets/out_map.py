from out_struct import c_type
from util import field_size


# c types with equivalent Qt types
q_types = [
    'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
    'int8_t',  'int16_t',  'int32_t',  'int64_t',
    'float', 'bool', 'char'
]

def map_type (data):
    tinfo = data['type']
    name = c_type(tinfo)

    if name in q_types:
        # make certain primitive types into their Qt counterparts
        name = 'Q' + name.title()

        if name[-2:] == '_T':
            name = name[:-2]

    if 'length' in data:
        name = 'std::array<{}, {}>'.format(name, data['length'])

    return name

# TODO #finish: deal with the weird bits:
#                * assigning to arrays
#                * custom types (ie. payload types)
#                * enums
#                * run & check
def out_map (data, name):
    def field (name, val):
        if 'map' in val:
            val = val['map']
        elif 'struct' in val:
            val = val['struct']

        start = '\t{ '

        # name
        name = '"'+name+'", '

        # type
        ftype = 'QVariant(static_cast<{}>('.format(map_type(val))

        # assign value
        bits = val['length'] if 'length' in val else 1
        bits *= field_size(val)
        if bits == -1:
            val = '/* TODO unknown */'
        elif bits > 32:
            val = '/* TODO too big ({}) */'.format(bits)
        else:
            val = 'buf.get({})'.format(bits)

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
