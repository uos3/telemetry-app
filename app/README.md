# Files

## Main Script

_main.cpp_ is the main script for invoking the application.

_cli.cpp_ and _cli.h_ are used to define a small CLI under the same program,
that doesn't launch the main GUI if invoked.

## GUI Interface

Qt C++ files that run the interface (Refer to _app.pro_):

1. _mainwindow.cpp_
2. _mainwindow.h_
3. _db_columns.cpp_
4. _db_columns.h_
5. _db_graph.cpp_
6. _db_graph.h_
7. _db_table.cpp_
8. _db_table.h_

## Reading in new packets

1. _input.h_
2. _input_file.cpp_
3. _input_file.h_
4. _input_socket.cpp_
5. _input_socket.h_

## Parsing the data locally

1. _buffer.cpp_
2. _buffer.h_
3. _packet.cpp_
3. _packet.h_

## Saving the parsed data locally

1. _db.cpp_
2. _db.h_
3. _output_db.cpp_
4. _output_db.h_

## Printing the parsed data as JSON

1. _output_json.cpp_
2. _output_json.h_

## Uploading to the server

1. _uploader.cpp_
2. _uploader.h_
3. _output_upload.cpp_
4. _output_upload.h_
