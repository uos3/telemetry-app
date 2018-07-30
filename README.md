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
+ [cereal (1.2.2)](https://uscilab.github.io/cereal)
	+ **to use**: [download](https://github.com/USCiLab/cereal/releases/tag/v1.2.2), extract, copy the `include/cereal` folder into `app/`.
