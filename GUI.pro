#-------------------------------------------------
#
# Project created by QtCreator 2015-08-23T17:16:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = it4kids-editor
TEMPLATE = app

# Build paths

INCLUDEPATH += src
DESTDIR=bin #Target file directory
OBJECTS_DIR=generated #Intermediate object files directory
MOC_DIR=generated #Intermediate moc files directory

# Location of python files
PYPATH = $$PWD/src/python

# C Files

SOURCES += \
    src/main.cpp\
    src/mainwindow.cpp \
    src/scene.cpp \
    src/categoryselect.cpp \
    src/dragableelement.cpp \
    src/dragelemcategory.cpp \
    src/dragelemlist.cpp \
    src/scriptarea.cpp \
    src/hatde.cpp \
    src/commandde.cpp \
    src/wrapperde.cpp \
    src/predicatede.cpp \
    src/paramdock.cpp \
    src/paramnumber.cpp \
    src/paramstring.cpp \
    src/paramdirection.cpp \
    src/paramdestination.cpp \
    src/paramkey.cpp \
    src/paraminteraction.cpp \
    src/parammessage.cpp \
    src/paramstopchoices.cpp \
    src/paramclone.cpp \
    src/paramcostume.cpp \
    src/parameffect.cpp \
    src/paramtouch.cpp \
    src/paramcolor.cpp \
    src/paramsound.cpp \
    src/reporterde.cpp \
    src/parammath.cpp \
    src/paramjoinwords.cpp \
    src/paramtype.cpp \
    src/paramdelim.cpp \
    src/paramvariables.cpp \
    src/paramlistselec.cpp \
    src/paramlistid.cpp \
    src/dockingarea.cpp \
    src/scriptdock.cpp \
    src/spriteselect.cpp \
    src/sprite.cpp

HEADERS  += \
    src/mainwindow.h \
    src/scene.h \
    src/categoryselect.h \
    src/dragableelement.h \
    src/dragelemcategory.h \
    src/dragelemlist.h \
    src/scriptarea.h \
    src/hatde.h \
    src/commandde.h \
    src/wrapperde.h \
    src/predicatede.h \
    src/paramdock.h \
    src/paramnumber.h \
    src/param.h \
    src/paramstring.h \
    src/paramdirection.h \
    src/paramdestination.h \
    src/paramkey.h \
    src/paraminteraction.h \
    src/parammessage.h \
    src/paramstopchoices.h \
    src/paramclone.h \
    src/paramcostume.h \
    src/parameffect.h \
    src/paramtouch.h \
    src/paramcolor.h \
    src/paramsound.h \
    src/reporterde.h \
    src/parammath.h \
    src/paramjoinwords.h \
    src/paramtype.h \
    src/paramdelim.h \
    src/paramvariables.h \
    src/paramlistselec.h \
    src/paramlistid.h \
    src/dockingarea.h \
    src/scriptdock.h \
    src/spriteselect.h \
    src/sprite.h

FORMS    += \
    src/mainwindow.ui

DISTFILES +=

RESOURCES += \
    src/resources.qrc

unix:!arch {
    CONFIG += link_pkgconfig
# Depending on distibution, python 2.7 is either called "python" or "python2"
    PKGCONFIG += python2
    # PKGCONFIG += python
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

pythondata.commands = $(COPY_DIR) $$shell_path($$PYPATH) $$shell_path($$OUT_PWD/$$DESTDIR/python)
first.depends = $(first) pythondata
export(first.depends)
export(pythondata.commands)

test.commands = echo tests not yet implemented 
export(test.commands)

QMAKE_EXTRA_TARGETS += first pythondata test
