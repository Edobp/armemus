#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T20:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = armemus
TEMPLATE = app


SOURCES += main.cpp\
        armemus.cpp \
    editorwindow.cpp \
    boardwindow.cpp

HEADERS  += armemus.h \
    editorwindow.h \
    boardwindow.h

FORMS    += armemus.ui \
    editorwindow.ui \
    boardwindow.ui
