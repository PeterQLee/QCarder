#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T22:17:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCarder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawstack.cpp \
    testscreen.cpp

HEADERS  += mainwindow.h \
    drawstack.h \
    testscreen.h

FORMS    += mainwindow.ui \
    modeselect.ui \
    testscreen.ui \
    createscreen.ui

DISTFILES +=
