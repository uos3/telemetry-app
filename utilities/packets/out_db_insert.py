from out_struct import c_name


def out_db_insert (data, name):
    n = name[0].lower()

    out = ('bool DB::store_packet ({}& {}, const QByteArray& b, '
           'QSqlQuery& query) {{\n').format(name, n)

    # initial insertion query string -- field names
    out += '\tQString qstr = "insert into {} ('.format(data['name']['sql'])
    for f in data['fields'].keys():
        new = '{}, '.format(f)
        if len((out + new).split('\n')[-1]) > 80:
            out += '"\n\t       "'
        out += new
    out = out[:-2]

    # initial insertion query string -- value names to bind
    out += ') values ('
    for f in data['fields'].keys():
        new = ':{}, '.format(f)
        if len((out + new).split('\n')[-1]) > 80:
            out += '"\n\t       "'
        out += new
    out = out[:-2]
    out += ');";\n'

    out += ('\tif (!query.prepare(qstr)) {{\n'
            '\t\tqCritical() << "Error preparing query for {} table.";\n'
            '\t\treturn false;\n'
            '\t}}\n\n').format(name)

    # binding values
    for f in data['fields'].keys():
        out += '\tquery.bindValue(":{0}", {1}.{2});\n'.format(f, n, c_name(f))

    out += ('\n\tif (!query.exec()) {{\n'
            '\t\tqCritical() << "error inserting {}: " '
            '<< query.lastError().text();\n'
            '\t\treturn false;\n'
            '\t}}\n').format(name)
    out += '\n\treturn true;\n'

    out += '}'

    return out
