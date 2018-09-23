# telemetry-app

Main UoS³ telemetry application

Purpose: Parse received packets from CubeSat, and upload onto server.

# TODO

## near future

1. Interface to read data from table in mySQL db and display row-by-row on screen. (Partially done)
2. Add buttons to navigate the rows. (Done)
3. Add basic graphing functionality. (TBC)

## less-near future

1. Integrate with data server. (Partially done)
2. Receive new upstream data from decoder-end. (TBC)
3. Be able to add timestamps to fresh data and push to db. (Done)

# Dependencies

Currently:

+ [Qt](https://www.qt.io)
* [MySQL](https://www.mysql.com/)
+ [cereal (1.2.2)](https://uscilab.github.io/cereal)
	+ **to use**: [download](https://github.com/USCiLab/cereal/releases/tag/v1.2.2), extract, copy the `include/cereal` folder into `app/`.

# Building

*Building the application has been tested on Windows and Ubuntu.*

## Windows

1. Clone or download the repo.
2. Download and install [Qt Creator](https://www.qt.io/).
3. (To use database functionality) Download and install [MySQL](https://www.mysql.com/).
4. [Download cereal](https:\\uscilab.github.io\cereal), and put the `cereal-X.X.X\include\cereal` folder into `app` (so you have eg. `telemetry-app\app\cereal\cereal.hpp`)
5. Launch Qt Creator, and import the project by pointing it to `C:\Path\to\the\repo\app\app.pro`.
6. Build -> Build project "app" (or press `Ctrl+B`).

## Ubuntu

You have two options:

### Just build it:

*(for minimal dependency downloads, and on servers without X)*

1. Clone the repo.
2. Install qt: `$ sudo apt install qt5-default`.
3. (For database functionality) install mysql, and the database driver `$ sudo apt install mysql-server libqt5sql5-mysql`
4. [Download cereal](https://uscilab.github.io/cereal), and put the `cereal-X.X.X/include/cereal` folder into `app/` (so you have eg. `telemetry-app/app/cereal/cereal.hpp`)
5. `$ cd /path/to/the/repo/app/`
6. `$ qmake`
7. `$ make`

### Build it with Qt Creator:

*(if you want to develop the application, or if 'just build' isn't working on its own)*

1. Clone the repo.
2. Install qt creator: `$ sudo apt install qt5creator`.
3. (For database functionality) install mysql, and the database driver `$ sudo apt install mysql-server libqt5sql5-mysql`
4. [Download cereal](https://uscilab.github.io/cereal), and put the `cereal-X.X.X/include/cereal` folder into `app/` (so you have eg. `telemetry-app/app/cereal/cereal.hpp`)
5. Launch Qt Creator, and import the project by pointing it to `/path/to/the/repo/app/app.pro`.
6. Build -> Build project "app" (or press `Ctrl+B`).

# Authors

Charles West-Taylor

Hubert Khoo Hui Boo

Mohammed Nawabuddin
