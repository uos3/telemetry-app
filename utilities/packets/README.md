# WIP: packet utilities

Utilities that allow you to only have to deal with the packet specification in
one place, with yaml files.

## yaml files

The yaml files form a central specification for the various types of packet that
can be read in from the cubesat.

It's best to have a look at one of these files to get an idea for how they
should be structured.

### structure

```yaml
version: 1.2
my_payload:
  field1: { type: { name: int, bits: 32, signed: true }, length: 3, desc: '3 numbers' }
  # ...
  fieldN: { type: { name: bool }, desc: 'true or false' }
```

A yaml file contains a version tag, and an object for the packet itself. The
name of the packet type matches that of the file. The packet object contains a
list of fields.

Each field can (currently) contain up to three sub-fields:

* `type`: An object representing the type of the field.
* `length`: An optional field. If set, the field will be interpreted as a list,
with `length` elements.
* `desc`: A description of what the field represents.

`type` is an object, in turn containing its own fields. for most types, only
`name` need be set. for `int`, the others are needed to further specify the
kind of integer. the fields are as follows:

* `name`: A basic name of the type -- `int`, `float`, `char`, `bool`,
`MyObject` etc.
* `bits`: The number of bits needed to store a value of this type.
* `signed`: A boolean, representing whether or not this type is signed.

So, for instance, a `uint32_t` in C++ would correspond to:

```yaml
my_int: { type: { name: int, bits: 32, signed: true }, desc: 'is a uint32_t' }
```

A 16 character string would be:

```yaml
hash: { type: { name: char }, length: 16, desc: '...' }
```

## parser.py

Generates various bits of code from the central yaml files.

### example usage

```bash
$ ./parser.py cereal_struct packet.yml status.yml
```

## yml2json

Converts a yaml file to json, and prints the result to stdout.

### example usage

```bash
$ ./yml2json.py packet.yml > packet.json
```
