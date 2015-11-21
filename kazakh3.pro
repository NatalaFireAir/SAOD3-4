QT += core
QT -= gui

TARGET = kazakh3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    queue.cpp \
    stack.cpp \
    mycollection.cpp \
    sorting.cpp

HEADERS += \
    queue.h \
    stack.h \
    mycollection.h \
    sorting.h

