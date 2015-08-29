#-------------------------------------------------
#
# Project created by QtCreator 2015-08-23T17:16:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    categoryselect.cpp \
    dragableelement.cpp \
    dragelemcategory.cpp \
    dragelemlist.cpp

HEADERS  += mainwindow.h \
    scene.h \
    categoryselect.h \
    dragableelement.h \
    dragelemcategory.h \
    dragelemlist.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
