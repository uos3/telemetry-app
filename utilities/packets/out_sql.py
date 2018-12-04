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
        # process a single field row.
        out = ''
        if 'sql' in val:
            val = val['sql']
        if 'length' in val and val['type']['name'] != 'char':
            # if we're dealing with an array, make N rows appended with _n.
            for i in range(val['length']):
                name_n = name + '_' + str(i+1)
                out += '\t' + name_n + ' ' + sql_type(val) + ',\n'
        else:
            # otherwise, output the field as normal.
            out +=  '\t' + name + ' ' + sql_type(val) + ',\n'

        # return the string for a single field.
        return out

    # process keys (declarations, at the start).
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

    # process fields.
    for f in data['fields'].keys():
        out += field(f, data['fields'][f])
    if 'special' in data and 'sql' in data['special']:
        for f in data['special']['sql']:
            out += field(f, data['special']['sql'][f])

    # process keys again (foreign key links, at the end).
    if 'keys' in data:
        if 'foreign' in data['keys']:
            out += '\n'
            for k in key_types['foreign']:
                out += '\tforeign key ' + k['name'] + ' references ' + k['table'] + '(' + k['name'] + '),\n'

    # chop off the last comma & add the closing paren.
    out = out[:-2] + '\n);'
    return out

