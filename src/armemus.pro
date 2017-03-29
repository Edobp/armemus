#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T04:05:50
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
qtHaveModule(opengl): QT += opengl

TARGET = armemus
TEMPLATE = app

INCLUDEPATH += \
    src

SOURCES +=\            
    armemus.cpp \
    amain.cpp \
    board/aboardtab.cpp \
    board/svgview.cpp \
    board/adebug.cpp \
    editor/aeditor.cpp \
    editor/aeditortab.cpp \
    editor/highlighter.cpp \
    project/aproject.cpp \
    project/abuild.cpp \
    project/adirectories.cpp \
    project/asymbols.cpp

HEADERS  += \
    armemus.h \
    board/adebug.h \
    board/aboardtab.h \
    editor/aeditor.h \
    editor/aeditortab.h \
    editor/highlighter.h \
    board/svgview.h \
    project/aproject.h \
    project/abuild.h \
    project/adirectories.h \
    project/asymbols.h \
    aincludes.h \
    adefinitions.h

FORMS    += \
    armemus.ui \
    board/aboardtab.ui \
    editor/aeditortab.ui \
    project/aproject.ui \
    project/abuild.ui \
    project/adirectories.ui \
    project/asymbols.ui

RESOURCES += \
    resources/icons.qrc \
    resources/text.qrc \
    resources/boards.qrc \
    resources/armemus.qrc
