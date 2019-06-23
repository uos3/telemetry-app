
# bit sizes of the basic types allowed in the spec
type_sizes = {
    'float': 32,
    'char': 8,
    'bool': 1,
    'time': 32
}

def field_size (data):
    # number of bits in a field.
    size = -1
    if 'bits' in data['type']:
        size = data['type']['bits']
    elif data['type']['name'] in type_sizes:
        size = type_sizes[data['type']['name']]

    if 'length' in data['type'] and size != -1:
        size *= data['type']['length']

    return size
