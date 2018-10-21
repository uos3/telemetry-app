#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T20:56:09
#
#-------------------------------------------------

QT += \
    core \
    gui \
    sql \
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

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
    main.cpp \
    mainwindow.cpp \
    secondwindow.cpp \
    topwindow.cpp \
    uploader.cpp \
    db.cpp \
    buffer.cpp \
    packet.cpp \
    cli.cpp \
    filehandler.cpp

HEADERS += \
    mainwindow.h \
    secondwindow.h \
    topwindow.h\
    uploader.h \
    db.h \
    packet.h \
    buffer.h \
    cli.h \
    filehandler.h

FORMS += \
    mainwindow.ui \
    secondwindow.ui \
    topwindow.ui \
