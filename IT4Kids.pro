#-------------------------------------------------
#
# Project created by QtCreator 2015-08-23T17:16:47
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
CONFIG += c++11
CONFIG += qscintilla2

INCLUDEPATH += src
DESTDIR=bin #Target file directory
OBJECTS_DIR=generated #Intermediate object files directory
MOC_DIR=generated #Intermediate moc files directory

# Location of python files
PYPATH = $$PWD/python
ASSETSPATH = $$PWD/Assets

TARGET = it4kids-editor
TEMPLATE = app

TRANSLATIONS = resources/translations/editor_de.ts

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/scene.cpp \
    src/scriptarea.cpp \
    src/dockingarea.cpp \
    src/spriteselect.cpp \
    src/sprite.cpp \
    src/param/paramclone.cpp \
    src/param/paramcolor.cpp \
    src/param/paramcostume.cpp \
    src/param/paramdelim.cpp \
    src/param/paramdestination.cpp \
    src/param/paramdirection.cpp \
    src/param/paramdock.cpp \
    src/param/parameffect.cpp \
    src/param/paraminteraction.cpp \
    src/param/paramjoinwords.cpp \
    src/param/paramkey.cpp \
    src/param/paramlistid.cpp \
    src/param/paramlistselec.cpp \
    src/param/parammath.cpp \
    src/param/parammessage.cpp \
    src/param/paramnumber.cpp \
    src/param/paramsound.cpp \
    src/param/paramstopchoices.cpp \
    src/param/paramstring.cpp \
    src/param/paramtouch.cpp \
    src/param/paramtype.cpp \
    src/param/paramvariables.cpp \
    src/audio/audioengine.cpp \
    src/audio/wavfile.cpp \
    src/audio/soundselect.cpp \
    src/costume/costume.cpp \
    src/costume/costumeselect.cpp \
    src/dragelem/categoryselect.cpp \
    src/dragelem/commandde.cpp \
    src/dragelem/draggableelement.cpp \
    src/dragelem/dragelemcategory.cpp \
    src/dragelem/dragelemlist.cpp \
    src/dragelem/hatde.cpp \
    src/dragelem/predicatede.cpp \
    src/dragelem/reporterde.cpp \
    src/dragelem/scriptdock.cpp \
    src/dragelem/wrapperde.cpp \
    src/teacher/studentlist.cpp \
    src/newspritename.cpp\
    src/codegenerator.cpp\
    src/saveloadclass.cpp \
    src/teacher/student.cpp \
    src/teacher/teacher.cpp \
    src/teacherlogin.cpp \
    src/pythoncontroller.cpp \
    src/param/paramcombobox.cpp \
    src/param/param.cpp

HEADERS  += src/mainwindow.h \
    src/scene.h \
    src/scriptarea.h \
    src/dockingarea.h \
    src/dragelem/scriptdock.h \
    src/spriteselect.h \
    src/sprite.h \
    src/param/param.h \
    src/param/paramclone.h \
    src/param/paramcolor.h \
    src/param/paramcostume.h \
    src/param/paramdelim.h \
    src/param/paramdestination.h \
    src/param/paramdirection.h \
    src/param/paramdock.h \
    src/param/parameffect.h \
    src/param/paraminteraction.h \
    src/param/paramjoinwords.h \
    src/param/paramkey.h \
    src/param/paramlistid.h \
    src/param/paramlistselec.h \
    src/param/parammath.h \
    src/param/parammessage.h \
    src/param/paramnumber.h \
    src/param/paramsound.h \
    src/param/paramstopchoices.h \
    src/param/paramstring.h \
    src/param/paramtouch.h \
    src/param/paramtype.h \
    src/param/paramvariables.h \
    src/audio/audioengine.h \
    src/audio/wavfile.h \
    src/audio/soundselect.h \
    src/costume/costume.h \
    src/costume/costumeselect.h \
    src/dragelem/categoryselect.h \
    src/dragelem/commandde.h \
    src/dragelem/draggableelement.h \
    src/dragelem/dragelemcategory.h \
    src/dragelem/dragelemlist.h \
    src/dragelem/hatde.h \
    src/dragelem/predicatede.h \
    src/dragelem/reporterde.h \
    src/dragelem/scriptdock.h \
    src/dragelem/wrapperde.h \
    src/teacher/studentlist.h \
    src/newspritename.h\
    src/codegenerator.h\
    src/saveloadclass.h \
    src/teacher/student.h \
    src/teacher/teacher.h \
    src/teacherlogin.h \
    src/pythoncontroller.h \
    src/param/paramcombobox.h

FORMS    += src/mainwindow.ui \
    src/newspritename.ui \
    src/teacherlogin.ui

RESOURCES += \
    resources/resources.qrc

unix:{
    QMAKE_CFLAGS += $$system(python3-config --cflags)
    QMAKE_CXXFLAGS += $$system(python3-config --cflags)
    LIBS += $$system(python3-config --ldflags)
}

win32:{
    PY_VERSIONS = 3.5 3.5-32 3.4 3.3
    for(PY_VERSION, PY_VERSIONS) {
        PY_HOME = $$quote($$system(reg query HKCU\\SOFTWARE\\Python\\PythonCore\\$$PY_VERSION\\InstallPath /ve))
        PY_HOME ~= s/.*(\\w:.*)/\\1
        !exists($$PY_HOME\\include\\Python.h) {
            PY_HOME = $$quote($$system(reg query HKLM\\SOFTWARE\\Python\\PythonCore\\$$PY_VERSION\\InstallPath /ve))
            PY_HOME ~= s/.*(\\w:.*)/\\1
            !exists($$PY_HOME\\include\\Python.h):next()
        }

        PY_LIB_BASENAME = python$${PY_VERSION}
        PY_LIB_BASENAME ~= s/\\./
        PY_LIB_BASENAME = $$section(PY_LIB_BASENAME, -, 0, 0)
        CONFIG(debug, debug|release):PY_LIB_BASENAME = $${PY_LIB_BASENAME}_d
        INCLUDEPATH *= $$PY_HOME\\include
        LIBS *= -L$$PY_HOME\\libs -l$${PY_LIB_BASENAME}
        message(Python$$PY_VERSION found at $$PY_HOME)
        break()
   }
}

pythondata.commands = $(COPY_DIR) $$shell_path($$PYPATH) $$shell_path($$OUT_PWD/$$DESTDIR/python)
assetsdata.commands += $(COPY_DIR) $$shell_path($$ASSETSPATH) $$shell_path($$OUT_PWD/$$DESTDIR/Assets)
first.depends = $(first) pythondata assetsdata
export(first.depends)
export(pythondata.commands)
export(assetsdata.commands)

QMAKE_EXTRA_TARGETS += first pythondata assetsdata
