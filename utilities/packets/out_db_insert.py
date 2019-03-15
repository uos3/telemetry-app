from out_struct import c_name, c_type
from util import field_size

def out_db_insert (data, name):
    n = name[0].lower()

    out = 'bool DB::store_packet ({}& {}, Buffer b) {{\n'.format(name, n)
    out += '\tbool success = false;\n\n'

    # initial insertion query string -- field names
    out += '\tQString qstr = "insert into {} ('.format(data['name']['sql'])
    for f in data['fields'].keys():
        out += '{}, '.format(f)
    out = out[:-2]

    # initial insertion query string -- value names to bind
    out += ') values ('
    for f in data['fields'].keys():
        out += ':{}, '.format(f)
    out = out[:-2]
    out += ');";\n'

    out += '\tif (!query.prepare(qstr)) {{ qCritical() << "Error preparing query for {} table."; }}\n\n'.format(name)

    # binding values
    for f in data['fields'].keys():
        out += '\tquery.bindValue(":{0}", {1}.{0});\n'.format(f, n)

    out += '\n\tsuccess = query.exec();\n'
    out += '\tif (!success) {{ qCritical() << "error inserting {}!: " << query.lastError().text(); }}\n'.format(name)
    out += '\n\treturn success;\n'

    out += '}'

    return out
