#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T20:02:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wordsmodel.cpp \
    addwordform.cpp \
    global.cpp \
    recitewordsform.cpp

HEADERS  += mainwindow.h \
    wordsmodel.h \
    addwordform.h \
    global.h \
    recitewordsform.h

OTHER_FILES += \
    words.xml
