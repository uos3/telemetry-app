from out_struct import c_name, c_type
from util import field_size

def out_parse_buffer (data, name):
    n = name[0]

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

    out = 'void from_buffer ({}& {}, Buffer b) {{\n'.format(name, n)

    for f in data['fields'].keys():
        out += field(f, data['fields'][f])

    out += '}'

    return out
