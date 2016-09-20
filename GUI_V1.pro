#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T04:05:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_V1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    board_w.cpp \
    editor_w.cpp

HEADERS  += mainwindow.h \
    board_w.h \
    editor_w.h

FORMS    += mainwindow.ui \
    board_w.ui \
    editor_w.ui
