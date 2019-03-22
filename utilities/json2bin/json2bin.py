# input:
#   json file with values
#   yml file with fields
#   something that describes the binfile structure (not sure if yml is enough?)

# output:
#   binary file compliant with the current packet spec (v0.2 at the moment)

import os
import sys
import json
import yaml
from collections import OrderedDict

packet_spec_filename = "packet.yml"
status_spec_filename = '../packets/status.yml'

payload_spec_filenames = {
    'config': '../packets/config.yml',
    'gps': '../packets/gps.yml',
    'health': '../packets/health.yml',
    'img': '../packets/img.yml',
    'imu': '../packets/imu.yml'
}

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



try:
    packet_type = sys.argv[1]
    json_filename = sys.argv[2]
except IndexError:
    print "ERROR: Missing arguments. You must supply a packet type and a path to the JSON file containing the values.\nUsage: `json2bin.py <config|gps|health|img|imu> <json>`"
    exit(1)

try:
    packet_spec_file = open(packet_spec_filename)
    status_spec_file = open(status_spec_filename)
except IOError:
    print "ERROR: could not find packet spec file ({}) or status_spec_file ({})".format(packet_spec_filename, status_spec_filename)
    exit(1)

packet_spec = ordered_load(packet_spec_file, Loader=yaml.SafeLoader)
status_spec = ordered_load(status_spec_file, Loader=yaml.SafeLoader)

try:
    payload_spec_filename = payload_spec_filenames[packet_type]
    payload_spec_file = open(payload_spec_filename)
    payload_spec = ordered_load(payload_spec_file, Loader=yaml.SafeLoader)
except Exception:
    print "ERROR: could not find the payload spec file for given payload type. Available payload types: {}".format(", ".join(payload_spec_filenames.keys()))
    exit(1)


try:
    json_file = open(json_filename)
except IOError:
    print "ERROR: .json input file does not exist"
    exit(1)


# try opening the JSON and yml files.
values = json.load(json_file)

field_list = OrderedDict(packet_spec['fields_pre'].items() + status_spec['fields'].items() + payload_spec['fields'].items() + packet_spec['fields_post'].items())

for field_name, field_info in field_list.items():
    print "{} -- {}".format(field_name, field_info['type']['name'])

# Just testing, needs to be done differently.
# First, iterate through the fields_pre. if name = None, generate zeroes to the given length.
# Then, iterate through status_spec fields. Fill from JSON.
# Iterate through payload_spec fields, fill from JSON.
# Last, iterate over fields_post. If name = None, generate zeroes to given length.
# (Maybe use the None logic for the JSON fields too?)
# (Make that a function, probably.)
#
# Or... function to check: if the field is in JSON, set it from there. If it is in spec, set it there. If neither, check type name: if None, generate to given length. If anything else, throw error?
