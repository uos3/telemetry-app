# WIP: packet utilities

Utilities that allow you to only have to deal with the packet specification in
one place, with yaml or json files.

The system has primarily been designed around yaml (and this file uses it in its
examples), however json is also supported.

## yaml files

The yaml files form a central specification for the various types of packet that
can be read in from the cubesat.

It's best to have a look at one of these files to get an idea for how they
should be structured.

### structure

```yaml
version: 1.2
name: my_payload
fields:
  field1: { type: { name: int, bits: 32, signed: true }, length: 3, desc: '3 numbers' }
  # ...
  fieldN: { type: { name: bool }, desc: 'true or false' }
```

#### version

A basic version number, purely for the benefit of human readers.

#### name

A basic string for the name of the packet. Supports specialisations for output
types, eg:

```yaml
name:
  struct: MyPayload
  sql:    my_payload
```

If the name is specialised but there's no specialisation for the current output
type, the filename will be used.

#### keys

```yaml
keys:
  primary:
    - { name: my_id }
  foreign:
    - { name: other_id, table: other }
```

Specifies the keys, for the `sql` output type.

#### special

```yaml
special:
  sql:
    frame_bin:   { type: { name: binary, bits: 3136 }, desc: 'The binary of the packet.' }
```

A list of fields that should only be output for a particular output type. They
are organised by output type.

#### fields

```yaml
fields:
  field1: { type: { name: int, bits: 32, signed: true }, length: 3, desc: '3 numbers' }
  # ...
  fieldN: { type: { name: bool }, desc: 'true or false' }
```

The main list of fields for the packet.

Each field can (currently) contain up to three sub-fields:

* `type`: An object representing the type of the field.
* `length`: An optional field. If set, the field will be interpreted as a list,
with `length` elements.
* `desc`: A description of what the field represents.

`type` is an object, in turn containing its own fields. for most types, only
`name` need be set. for `int`, the others are needed to further specify the
kind of integer. the fields are as follows:

* `name`: A basic name of the type. The currently supported types are:
  * `int`: Integer. Requires also specifying `bits` and `signed`.
  * `float`: Floating point decimal number.
  * `char`: Character.
  * `bool`: Boolean.
  * `time`: Timestamp. Equivalent to `uint32_t` in C++, and `timestamp` in
  MySQL.
  * `binary`: Binary data. Requires also specifying `bits`.
  * `MyObject`: -- Any other type, not matched by one above, will be output
  literally.
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

Fields can be specialised for different output types, by using subobjects. For
instance:

```yaml
fields:
  # ...
  payload_type:
    struct:      { type: { name: PayloadType } }
    sql:         { type: { name: "enum('gps', 'imu', 'health', 'img', 'config')" } }
    desc: ''
  # ...
```

(note above the use of `enum` in the SQL typename. Since this isn't a known
type, the parser will just paste it through to the output).

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
