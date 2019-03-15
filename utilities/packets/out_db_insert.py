from out_struct import c_name, c_type
from util import field_size

def out_db_insert (data, name):
    n = name[0].lower()

    def field (name, val):
        res = ''

        f_name = c_name(name)
        f_type = c_type(val['type'])
        f_size = field_size(val)
        f_len = val['length'] if 'length' in val else 1

        if f_len == 1:
            res = '\t{}.{} = static_cast<{}>(b.get({}));\n'.format(
                n, f_name, f_type, f_size)
        else:
            actual_len = f_len + 1 if f_type == 'char' else f_len

            res += '\t{} _{}[{}];\n'.format(f_type, f_name, actual_len)
            res += '\tfor (int i=0; i<{}; i++) ' \
                   '{{ _{}[i] = static_cast<{}>(b.get({})); }}\n'.format(
                       f_len, f_name, f_type, f_size)
            if f_type == 'char':
                res += '\t_{}[{}] = \'\\0\';\n'.format(f_name, actual_len - 1)
            res += '\tstd::copy(_{0}, _{0}+{1}, {2}.{0});\n'.format(
                       f_name, actual_len, n)

        return res

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
