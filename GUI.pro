#-------------------------------------------------
#
# Project created by QtCreator 2015-08-23T17:16:47
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = it4kids-editor
TEMPLATE = app

SOURCES += src/main.cpp\
    src/GUI/mainwindow.cpp \
    src/GUI/scene.cpp \
    src/GUI/scriptarea.cpp \
    src/GUI/dockingarea.cpp \
    src/GUI/spriteselect.cpp \
    src/GUI/sprite.cpp \
    src/GUI/param/paramclone.cpp \
    src/GUI/param/paramcolor.cpp \
    src/GUI/param/paramcostume.cpp \
    src/GUI/param/paramdelim.cpp \
    src/GUI/param/paramdestination.cpp \
    src/GUI/param/paramdirection.cpp \
    src/GUI/param/paramdock.cpp \
    src/GUI/param/parameffect.cpp \
    src/GUI/param/paraminteraction.cpp \
    src/GUI/param/paramjoinwords.cpp \
    src/GUI/param/paramkey.cpp \
    src/GUI/param/paramlistid.cpp \
    src/GUI/param/paramlistselec.cpp \
    src/GUI/param/parammath.cpp \
    src/GUI/param/parammessage.cpp \
    src/GUI/param/paramnumber.cpp \
    src/GUI/param/paramsound.cpp \
    src/GUI/param/paramstopchoices.cpp \
    src/GUI/param/paramstring.cpp \
    src/GUI/param/paramtouch.cpp \
    src/GUI/param/paramtype.cpp \
    src/GUI/param/paramvariables.cpp \
    src/GUI/audio/audioengine.cpp \
    src/GUI/audio/wavfile.cpp \
    src/GUI/audio/soundselect.cpp \
    src/GUI/costume/costume.cpp \
    src/GUI/costume/costumeselect.cpp \
    src/GUI/dragelem/categoryselect.cpp \
    src/GUI/dragelem/commandde.cpp \
    src/GUI/dragelem/dragableelement.cpp \
    src/GUI/dragelem/dragelemcategory.cpp \
    src/GUI/dragelem/dragelemlist.cpp \
    src/GUI/dragelem/hatde.cpp \
    src/GUI/dragelem/predicatede.cpp \
    src/GUI/dragelem/reporterde.cpp \
    src/GUI/dragelem/scriptdock.cpp \
    src/GUI/dragelem/wrapperde.cpp \
    src/GUI/teacher/studentlist.cpp

HEADERS  += src/GUI/mainwindow.h \
    src/GUI/scene.h \
    src/GUI/scriptarea.h \
    src/GUI/dockingarea.h \
    src/GUI/scriptdock.h \
    src/GUI/spriteselect.h \
    src/GUI/sprite.h \
    src/GUI/param/param.h \
    src/GUI/param/paramclone.h \
    src/GUI/param/paramcolor.h \
    src/GUI/param/paramcostume.h \
    src/GUI/param/paramdelim.h \
    src/GUI/param/paramdestination.h \
    src/GUI/param/paramdirection.h \
    src/GUI/param/paramdock.h \
    src/GUI/param/parameffect.h \
    src/GUI/param/paraminteraction.h \
    src/GUI/param/paramjoinwords.h \
    src/GUI/param/paramkey.h \
    src/GUI/param/paramlistid.h \
    src/GUI/param/paramlistselec.h \
    src/GUI/param/parammath.h \
    src/GUI/param/parammessage.h \
    src/GUI/param/paramnumber.h \
    src/GUI/param/paramsound.h \
    src/GUI/param/paramstopchoices.h \
    src/GUI/param/paramstring.h \
    src/GUI/param/paramtouch.h \
    src/GUI/param/paramtype.h \
    src/GUI/param/paramvariables.h \
    src/GUI/audio/audioengine.h \
    src/GUI/audio/wavfile.h \
    src/GUI/audio/soundselect.h \
    src/GUI/costume/costume.h \
    src/GUI/costume/costumeselect.h \
    src/GUI/dragelem/categoryselect.h \
    src/GUI/dragelem/commandde.h \
    src/GUI/dragelem/dragableelement.h \
    src/GUI/dragelem/dragelemcategory.h \
    src/GUI/dragelem/dragelemlist.h \
    src/GUI/dragelem/hatde.h \
    src/GUI/dragelem/predicatede.h \
    src/GUI/dragelem/reporterde.h \
    src/GUI/dragelem/scriptdock.h \
    src/GUI/dragelem/wrapperde.h \
    src/GUI/teacher/studentlist.h

FORMS    += src/GUI/mainwindow.ui

RESOURCES += \
    src/GUI/resources.qrc


win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/GUI/QScintilla/ -lqscintilla2
else:win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/GUI/QScintilla/ -lqscintilla2
else:unix: LIBS += -L$$PWD/src/GUI/QScintilla/ -lqscintilla2

INCLUDEPATH += $$PWD/src/GUI/QScintilla \
    $$PWD/src \
    $$PWD/src/GUI \
    $$PWD/src/GUI/audio \
    $$PWD/src/GUI/costume \
    $$PWD/src/GUI/param \
    $$PWD/src/GUI/dragelem \
    $$PWD/src/GUI/teacher
DEPENDPATH += $$PWD/src/GUI/QScintilla \
    $$PWD/src \
    $$PWD/src/GUI \
    $$PWD/src/GUI/audio \
    $$PWD/src/GUI/costume \
    $$PWD/src/GUI/param \
    $$PWD/src/GUI/dragelem \
    $$PWD/src/GUI/teacher

