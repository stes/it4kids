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
    dragelemlist.cpp \
    scriptarea.cpp \
    hatde.cpp \
    commandde.cpp \
    wrapperde.cpp \
    predicatede.cpp \
    paramdock.cpp \
    paramnumber.cpp \
    paramstring.cpp \
    paramdirection.cpp \
    paramdestination.cpp \
    paramkey.cpp \
    paraminteraction.cpp \
    parammessage.cpp \
    paramstopchoices.cpp \
    paramclone.cpp \
    paramcostume.cpp \
    parameffect.cpp \
    paramtouch.cpp \
    paramcolor.cpp \
    paramsound.cpp \
    reporterde.cpp \
    parammath.cpp \
    paramjoinwords.cpp \
    paramtype.cpp \
    paramdelim.cpp \
    paramvariables.cpp \
    paramlistselec.cpp \
    paramlistid.cpp \
    dockingarea.cpp \
    scriptdock.cpp \
    spriteselect.cpp \
    sprite.cpp

HEADERS  += mainwindow.h \
    scene.h \
    categoryselect.h \
    dragableelement.h \
    dragelemcategory.h \
    dragelemlist.h \
    scriptarea.h \
    hatde.h \
    commandde.h \
    wrapperde.h \
    predicatede.h \
    paramdock.h \
    paramnumber.h \
    param.h \
    paramstring.h \
    paramdirection.h \
    paramdestination.h \
    paramkey.h \
    paraminteraction.h \
    parammessage.h \
    paramstopchoices.h \
    paramclone.h \
    paramcostume.h \
    parameffect.h \
    paramtouch.h \
    paramcolor.h \
    paramsound.h \
    reporterde.h \
    parammath.h \
    paramjoinwords.h \
    paramtype.h \
    paramdelim.h \
    paramvariables.h \
    paramlistselec.h \
    paramlistid.h \
    dockingarea.h \
    scriptdock.h \
    spriteselect.h \
    sprite.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc

unix{
    CONFIG += link_pkgconfig
    PKGCONFIG += python
}

win32:{
   PY_VERSIONS = 2.7 2.6
   for(PY_VERSION, PY_VERSIONS){
       system(reg query HKLM\\SOFTWARE\\Python\\PythonCore\\$$PY_VERSION\\InstallPath /ve) {
           PY_HOME = $$quote($$system(reg query HKLM\\SOFTWARE\\Python\\PythonCore\\$$PY_VERSION\\InstallPath /ve))
           PY_HOME ~= s/.*(\\w:.*)/\\1
           !exists($$PY_HOME\\include\\Python.h):next()
           INCLUDEPATH *= $$PY_HOME\\include
 
           PY_LIB_BASENAME = python$${PY_VERSION}
           PY_LIB_BASENAME ~= s/\\./
           CONFIG(debug, debug|release):PY_LIB_BASENAME = $${PY_LIB_BASENAME}_d
           LIBS *= $$PY_HOME\\libs\\$${PY_LIB_BASENAME}.lib
           message(Python$$PY_VERSION found at $$PY_HOME)
           break()
       }
   }
}

Release:pythondata.commands = $(COPY_DIR) $$shell_path($$PWD/python) $$shell_path($$OUT_PWD/release/python)
Debug:pythondata.commands = $(COPY_DIR) $$shell_path($$PWD/python) $$shell_path($$OUT_PWD/debug/python)
first.depends = $(first) pythondata
export(first.depends)
export(pythondata.commands)
QMAKE_EXTRA_TARGETS += first pythondata
