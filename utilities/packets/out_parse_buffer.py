from out_struct import c_name, c_type
from util import field_size


def out_parse_buffer (data, name):
    n = name[0].lower()

    def field (name, val):
        res = ''

        # get relevant info
        f_name = c_name(name)
        f_type = c_type(val['type'])
        f_size = field_size(val)
        f_len = val['length'] if 'length' in val else 1

        if f_len == 1:
            # single value
            if f_type == 'float':
                # floats need a reinterpret cast
                res = ('\tuint32_t raw_{0} = b.get({1});\n'
                       '\t{2}.{0} = reinterpret_cast<{3}&>(raw_{0});\n').format(
                    f_name, f_size, n, f_type)
            else:
                # standard cast
                res = '\t{}.{} = static_cast<{}>(b.get({}));\n'.format(
                    n, f_name, f_type, f_size)
        else:
            # array of values
            actual_len = f_len + 1 if f_type == 'char' else f_len

            res += '\t{} {}[{}];\n'.format(f_type, f_name, actual_len)
            if f_type == 'float':
                # array of floats
                res += ('\tfor (int i=0; i<{0}; i++) {{\n'
                        '\t\tuint32_t raw_{1} = b.get({2});\n'
                        '\t\t{1}[i] = reinterpret_cast<{3}&>(raw_{1});\n'
                        '\t}}\n').format(f_len, f_name, f_size, f_type)
            else:
                # standard array
                res += ('\tfor (int i=0; i<{}; i++) '
                       '{{ {}[i] = static_cast<{}>(b.get({})); }}\n').format(
                           f_len, f_name, f_type, f_size)

            if f_type == 'char':
                # strings need a null termination character
                res += '\t{}[{}] = \'\\0\';\n'.format(f_name, actual_len - 1)

            res += '\tstd::copy({0}, {0}+{1}, {2}.{0});\n'.format(
                       f_name, actual_len, n)

        return res

    out = 'void from_buffer ({}& {}, Buffer b) {{\n'.format(name, n)

    for f in data['fields'].keys():
        out += field(f, data['fields'][f])

    out += '}'

    return out
