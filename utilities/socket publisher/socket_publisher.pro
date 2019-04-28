QT += \
    core \
    network

TARGET = socket_pub
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp
