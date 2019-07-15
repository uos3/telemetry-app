#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T20:56:09
#
#-------------------------------------------------

QT += \
    charts \
    core \
    gui \
    network \
    sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

CONFIG(debug, debug|release) {
    DESTDIR = ../bin/debug
    DLLDESTDIR = ../bin/debug
    OBJECTS_DIR = ../build/debug
    MOC_DIR = ../build/debug
    UI_DIR = ../build/debug
    RCC_DIR = ../build/debug
} else {
    DESTDIR = ../bin/release
    DLLDESTDIR = ../bin/release
    OBJECTS_DIR = ../build/release
    MOC_DIR = ../build/release
    UI_DIR = ../build/release
    RCC_DIR = ../build/release
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    buffer.cpp \
    cli.cpp \
    # currentstatus.cpp \
    # datawindow.cpp \
    db.cpp \
    db_table.cpp \
    input_file.cpp \
    input_socket.cpp \
    main.cpp \
    mainwindow.cpp \
    output_db.cpp \
    output_json.cpp \
    output_upload.cpp \
    packet.cpp \
    # topwindow.cpp \
    uploader.cpp \
    utility.cpp

HEADERS += \
    buffer.h \
    cli.h \
    # currentstatus.h \
    # datawindow.h \
    db.h \
    db_table.h \
    input.h \
    input_file.h \
    input_socket.h \
    mainwindow.h \
    output.h \
    output_db.h \
    output_json.h \
    output_upload.h \
    packet.h \
    # topwindow.h\
    uploader.h \
    utility.h

# FORMS += \
#     currentstatus.ui \
#     datawindow.ui \
#     topwindow.ui
