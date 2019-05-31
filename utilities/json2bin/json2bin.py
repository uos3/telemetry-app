# input:
#   json file with values
#   yml file with fields
#   something that describes the binfile structure (not sure if yml is enough?)

# output:
#   binary file compliant with the current packet spec (v0.2 at the moment)

import argparse
import json
import yaml
from collections import OrderedDict
from bitstring import BitArray
from datetime import datetime


payload_spec_filenames = {
    'config': '../packets/config.yml',
    'gps': '../packets/gps.yml',
    'health': '../packets/health.yml',
    'img': '../packets/img.yml',
    'imu': '../packets/imu.yml'
}

default_packet_spec_filename = 'packet_v1.2.yml'
default_status_spec_filename = '../packets/status.yml'
verbose = False
debug = False


def print_debug(str=''):
    if debug:
        print str


def print_log(str=''):
    if verbose:
        print str


def print_error(str=''):
    print str


# https://stackoverflow.com/questions/5121931/in-python-how-can-you-load-yaml-mappings-as-ordereddicts
def ordered_load(stream, Loader=yaml.Loader, object_pairs_hook=OrderedDict):
    class OrderedLoader(Loader):
        pass

    def construct_mapping(loader, node):
        loader.flatten_mapping(node)
        return object_pairs_hook(loader.construct_pairs(node))
    OrderedLoader.add_constructor(
        yaml.resolver.BaseResolver.DEFAULT_MAPPING_TAG,
        construct_mapping)
    return yaml.load(stream, OrderedLoader)


def get_payload_code(type, packet_spec):
    code_value = packet_spec['payload_types']['codes'][type]
    code_length = packet_spec['payload_types']['code_length']
    print_debug("code value: {}; code length: {}".format(code_value, code_length))
    return BitArray(int=code_value, length=code_length)


def get_value(field, json={}):
    field_name = field[0]
    print_debug("get_value '{}':".format(field_name))
    value = None
    try:
        value = json[field_name]
        return value
        # TODO test: boolean false is accepted
    except KeyError:
        print_debug('  value not in JSON')

    try:
        value = field[1]["value"]
        return value
    except KeyError:
        print_debug('  no default value')

    return value


def make_bin_value(field, value):
    # TODO write tests for this function (how?????)
    name = field[0]
    field_info = field[1]["type"]
    field_type = field_info["name"]
    bits = None

    # modify the field type name to handle arrays
    try:
        field_length = field[1]["length"]
        if field_length > 1:
            field_type = "{}_array".format(field_type)
    except KeyError:
        pass

    print_log("{} -- {}, value to set: {}, {} bits".format(name, field_type, value, field_info['bits']))

    # no default value = no conversion needed, just generate zeroes to the correct length
    if value is None:
        bits = BitArray(field_info['bits'])
        return bits

    # no type = take the default value as binary string
    if field_type is None:
        bits = BitArray(bin=value)

    try:
        if (field_type == 'int' and field_info['signed']):
            bits = BitArray(int=value, length=field_info['bits'])
        elif (field_type == 'int' or field_type == 'time'):
            # time is unix epoch = integer
            bits = BitArray(uint=value, length=field_info['bits'])
        elif (field_type == 'float'):
            bits = BitArray(floatle=value, length=field_info['bits'])
        elif (field_type == 'bool'):
            bits = BitArray(bool=value)
        elif (field_type == 'bool_array'):
            bool_string = ''
            for x in value:
                if x:
                    char = "1"
                else:
                    char = "0"
                bool_string = bool_string + char
            bits = BitArray(bin=bool_string)
        elif (field_type == 'char_array'):
            # ...string. It's a STRING. Thanks for nothing, C++.
            print_debug("  field: {}".format(name))
            print_debug("  input value length: {}".format(len(value)))
            print_debug("  expected length: {}".format(field_length))
            if not field_length == len(value):
                print_error("FATAL: input string for '{}' has incorrect length ({}, expected {})".format(name, len(value), field_length))
                exit(1)
            bits = BitArray(bytes=value.encode('utf-8'))
    except Exception, e:
        print_error("FATAL: can't set value of {}.".format(name))
        print_error("  Incorrect input value, {}".format(str(e)))
        exit(1)

    return bits


def main():
    parser = argparse.ArgumentParser(description='Generate a binfile from JSON input.')
    parser.add_argument("-v", "--verbose", help="increase output verbosity", action="store_true")
    parser.add_argument("--debug", help="show debug logs", action="store_true")
    parser.add_argument('-p', '--packet_spec', dest='packet_spec_filename', default=default_packet_spec_filename, help='packet specification yml file')
    parser.add_argument('-s', '--status_spec', dest='status_spec_filename', default=default_status_spec_filename, help='status data specification yml file')
    parser.add_argument('-P', '--payload_spec', dest='payload_spec_filename', help='payload data specification yml file')
    parser.add_argument('packet_type', choices=['config', 'gps', 'health', 'img', 'imu'], help="type of packet to generate")
    parser.add_argument("json_filename", help='file with input values')

    args = parser.parse_args()

    global debug
    debug = args.debug

    global verbose
    verbose = args.verbose or args.debug

    try:
        packet_spec_file = open(args.packet_spec_filename)
        status_spec_file = open(args.status_spec_filename)
    except IOError:
        print_error("ERROR: could not find packet spec file ({}) or status_spec_file) ({})".format(args.packet_spec_filename, args.status_spec_filename))
        exit(1)

    packet_spec = ordered_load(packet_spec_file, Loader=yaml.SafeLoader)
    status_spec = ordered_load(status_spec_file, Loader=yaml.SafeLoader)

    try:
        if not args.payload_spec_filename:
            args.payload_spec_filename = payload_spec_filenames[args.packet_type]
        payload_spec_file = open(args.payload_spec_filename)
        payload_spec = ordered_load(payload_spec_file, Loader=yaml.SafeLoader)
    except Exception:
        print_error("ERROR: could not find the payload spec file for given payload type. Available payload types: {}".format(", ".join(payload_spec_filenames.keys())))
        exit(1)

    try:
        json_file = open(args.json_filename)
    except IOError:
        print_error("ERROR: .json input file does not exist")
        exit(1)

    # try opening the JSON and yml files.
    input = json.load(json_file)
    input = input["p"]
    print_debug("INPUT:")
    print_debug(input)
    print_debug("-----")

    values = []

    # prefix fields:
    for field in packet_spec['fields_pre'].items():
        value = get_value(field, input)
        values.append(make_bin_value(field, value))

    values.append(get_payload_code(args.packet_type, packet_spec))

    # status fields:
    for field in status_spec['fields'].items():
        value = get_value(field, input["status"])
        values.append(make_bin_value(field, value))

    # payload fields:
    for field in payload_spec['fields'].items():
        value = get_value(field, input["payload." + args.packet_type])
        values.append(make_bin_value(field, value))

    # postfix fields:
    for field in packet_spec['fields_post'].items():
        value = get_value(field, input)
        values.append(make_bin_value(field, value))

    binary = BitArray('').join(values)
    bitlength = len(binary.bin)
    mod = bitlength % 8

    if mod > 0:
        choice = raw_input("WARNING: The bit length of this packet doesn't add up to complete bytes ({} % 8 = {}). The generated bin file will be padded with 0s. Proceed? [Y/n] ".format(bitlength, mod))

        if choice is 'n':
            exit(1)

    time_created = datetime.now().strftime('%Y%m%d_%H%M%S')

    fbin = open(args.packet_type + time_created + '.bin', 'wb')
    binary.tofile(fbin)
    fbin.close()

    ftxt = open(args.packet_type + time_created + '.txt', 'w')
    ftxt.write(binary.bin)
    ftxt.close()

    # join BinArrays into one; create a binfile

    # field_list = OrderedDict(packet_spec['fields_pre'].items() + status_spec['fields'].items() + payload_spec['fields'].items() + packet_spec['fields_post'].items())


if __name__ == '__main__':
    main()
