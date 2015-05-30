#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T22:17:51
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH +=/Library/Frameworks/Python.framework/Versions/3.4/include/python3.4m
LIBS+= -L/Library/Frameworks/Python.framework/Versions/3.4/lib/ -lpython3.4m
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCarder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawstack.cpp \
    testscreen.cpp \
    handlePython.cpp \
    createscreen.cpp \
    colordisplay.cpp

HEADERS  += mainwindow.h \
    drawstack.h \
    testscreen.h \
    handlePython.h \
    createscreen.h \
    colordisplay.h

FORMS    += mainwindow.ui \
    modeselect.ui \
    testscreen.ui \
    createscreen.ui

DISTFILES +=


