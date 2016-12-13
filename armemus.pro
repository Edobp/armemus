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
    src/armemus.cpp \
    src/amain.cpp \
    src/board/aboardtab.cpp \
    src/board/svgview.cpp \
    src/board/adebug.cpp \
    src/editor/aeditor.cpp \
    src/editor/aeditortab.cpp \
    src/editor/highlighter.cpp \
    src/project/aproject.cpp \
    src/project/abuild.cpp \
    src/project/adirectories.cpp \
    src/project/asymbols.cpp

HEADERS  += \
    src/armemus.h \
    src/armemus_def.h \
    src/board/adebug.h \
    src/board/aboardtab.h \
    src/editor/aeditor.h \
    src/editor/aeditortab.h \
    src/editor/highlighter.h \
    src/board/svgview.h \
    src/project/aproject.h \
    src/project/abuild.h \
    src/project/adirectories.h \
    src/project/asymbols.h

FORMS    += \
    src/armemus.ui \
    src/board/aboardtab.ui \
    src/editor/aeditortab.ui \
    src/project/aproject.ui \
    src/project/abuild.ui \
    src/project/adirectories.ui \
    src/project/asymbols.ui

RESOURCES += \
    resources/icons.qrc \
    resources/text.qrc \
    resources/boards.qrc \
    resources/armemus.qrc
