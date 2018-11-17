#!/usr/bin/env python3

import sys
import yaml # pip package PyYAML
import json

def main ():
    if len(sys.argv) < 2:
        print('please supply a file name.')
        return

    with open(sys.argv[1], 'r') as file:
        data = yaml.load(file)
        print(json.dumps(data, indent=4))

if __name__ == '__main__':
    main()
