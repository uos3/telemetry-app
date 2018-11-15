# telemetry-app

Main UoS³ telemetry application

Purpose: Parse received packets from CubeSat, and upload onto server.

# To Do

## Near future

1. Interface to read data from table in mySQL db and display row-by-row on screen. (Partially done)
2. Add buttons to navigate the rows. (Done)
3. Add basic graphing functionality. (TBC)

## Less-near future

1. Integrate with data server. (Partially done)
2. Receive new upstream data from decoder-end. (Partially done)
3. Be able to add timestamps to fresh data and push to db. (Done)

# Dependencies

Currently:

* [Qt](https://www.qt.io)
* [MySQL](https://www.mysql.com/)

# Other Libraries Used

* [cereal (1.2.2)](https://uscilab.github.io/cereal)
	* For simplicity, the source code of cereal is included in the repo, in `app/cereal`.

# Building

*Building the application has been tested on Windows and Ubuntu.*

## Windows

1. Clone or download the repo.
2. Download and install [Qt Creator](https://www.qt.io/).
3. (To use database functionality) Download and install [MySQL](https://www.mysql.com/).
4. Create a `secrets` file, as discussed below.
5. Launch Qt Creator, and import the project by pointing it to `C:\Path\to\the\repo\app\app.pro`.
6. Build -> Build project "app" (or press `Ctrl+B`).

## Ubuntu

You have two options:

### Just build it:

*(for minimal dependency downloads, and on servers without X)*

1. Clone the repo.
2. Create a `secrets` file, as discussed below.
3. Install qt: `$ sudo apt install qt5-default`.
4. (For database functionality) install mysql, and the database driver `$ sudo apt install mysql-server libqt5sql5-mysql`
5. `$ cd /path/to/the/repo/app/`
6. `$ qmake`
7. `$ make`

### Build it with Qt Creator:

*(if you want to develop the application, or if 'just build' isn't working on its own)*

1. Clone the repo.
2. Create a `secrets` file, as discussed below.
3. Install qt creator: `$ sudo apt install qtcreator`.
4. (For database functionality) install mysql, and the database driver `$ sudo apt install mysql-server libqt5sql5-mysql`
5. Launch Qt Creator, and import the project by pointing it to `/path/to/the/repo/app/app.pro`.
6. Build -> Build project "app" (or press `Ctrl+B`).

# The `secrets` file

Information on connecting to the server/local database is currently stored in
the `app/secrets/secrets.h` file. This file is not included in the repo.
However, there is an example file, `secrets.exmaple.h`, to show you the basic
structure:

```cpp
#include <string>

namespace secrets {

// for the upload server.
static const std::string address = "localhost:8080";
static const std::string app_key = "my super cool app key";

// for the local database.
static const std::string username = "root";
static const std::string password = "hunter2";

}
```

To make a secrets file, simply fill in the correct values, and save the file as
`app/secrets/secrets.h`.

# Authors

Charlie West-Taylor

Hubert Khoo Hui Boo

James Robert Brown

Mohammed Nawabuddin