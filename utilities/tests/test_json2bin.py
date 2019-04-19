import unittest
import sys
import os
from collections import OrderedDict

testdir = os.path.dirname(__file__)
srcdir = '../json2bin'
sys.path.insert(0, os.path.abspath(os.path.join(testdir, srcdir)))

import json2bin  # noqa: E402


class TestGetValue(unittest.TestCase):
    def setUp(self):
        self.spec_default_value = 123
        self.field_spec_without_default = ['testField', OrderedDict([('type', OrderedDict([('name', 'char'), ('bits', 16)])), ('value', None), ('desc', '')])]
        self.field_spec_with_default = ['testField', OrderedDict([('type', OrderedDict([('name', 'char'), ('bits', 16)])), ('value', self.spec_default_value), ('desc', '')])]

        self.json_value = 321
        self.json_without_value = {
            "wrong_field": 1,
            "another_wrong_field": 2,
        }
        self.json_with_value = {
            "wrong_field": 1,
            "another_wrong_field": 2,
            'testField': self.json_value
        }

    def test_no_values(self):
        value = json2bin.get_value(self.field_spec_without_default)
        self.assertEquals(value, None)

    def test_with_json_no_values(self):
        value = json2bin.get_value(self.field_spec_without_default, self.json_without_value)
        self.assertEquals(value, None)

    def test_spec_has_default(self):
        value = json2bin.get_value(self.field_spec_with_default)
        self.assertEquals(value, self.spec_default_value)

    def test_spec_no_json_yes(self):
        value = json2bin.get_value(self.field_spec_without_default, self.json_with_value)
        self.assertEquals(value, self.json_value)

    def test_spec_yes_json_no(self):
        value = json2bin.get_value(self.field_spec_with_default, self.json_without_value)
        self.assertEquals(value, self.spec_default_value)

    def test_both_json_value_has_priority(self):
        value = json2bin.get_value(self.field_spec_with_default, self.json_with_value)
        self.assertEquals(value, self.json_value)


if __name__ == '__main__':
    unittest.main()
