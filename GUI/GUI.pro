#-------------------------------------------------
#
# Project created by QtCreator 2015-08-23T17:16:47
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    scene.cpp \
    scriptarea.cpp \
    dockingarea.cpp \
    spriteselect.cpp \
    sprite.cpp \
    param/paramclone.cpp \
    param/paramcolor.cpp \
    param/paramcostume.cpp \
    param/paramdelim.cpp \
    param/paramdestination.cpp \
    param/paramdirection.cpp \
    param/paramdock.cpp \
    param/parameffect.cpp \
    param/paraminteraction.cpp \
    param/paramjoinwords.cpp \
    param/paramkey.cpp \
    param/paramlistid.cpp \
    param/paramlistselec.cpp \
    param/parammath.cpp \
    param/parammessage.cpp \
    param/paramnumber.cpp \
    param/paramsound.cpp \
    param/paramstopchoices.cpp \
    param/paramstring.cpp \
    param/paramtouch.cpp \
    param/paramtype.cpp \
    param/paramvariables.cpp \
    audio/audioengine.cpp \
    audio/wavfile.cpp \
    audio/soundselect.cpp \
    costume/costume.cpp \
    costume/costumeselect.cpp \
    dragelem/categoryselect.cpp \
    dragelem/commandde.cpp \
    dragelem/dragableelement.cpp \
    dragelem/dragelemcategory.cpp \
    dragelem/dragelemlist.cpp \
    dragelem/hatde.cpp \
    dragelem/predicatede.cpp \
    dragelem/reporterde.cpp \
    dragelem/scriptdock.cpp \
    dragelem/wrapperde.cpp

HEADERS  += mainwindow.h \
    scene.h \
    scriptarea.h \
    dockingarea.h \
    scriptdock.h \
    spriteselect.h \
    sprite.h \
    param/param.h \
    param/paramclone.h \
    param/paramcolor.h \
    param/paramcostume.h \
    param/paramdelim.h \
    param/paramdestination.h \
    param/paramdirection.h \
    param/paramdock.h \
    param/parameffect.h \
    param/paraminteraction.h \
    param/paramjoinwords.h \
    param/paramkey.h \
    param/paramlistid.h \
    param/paramlistselec.h \
    param/parammath.h \
    param/parammessage.h \
    param/paramnumber.h \
    param/paramsound.h \
    param/paramstopchoices.h \
    param/paramstring.h \
    param/paramtouch.h \
    param/paramtype.h \
    param/paramvariables.h \
    audio/audioengine.h \
    audio/wavfile.h \
    audio/soundselect.h \
    costume/costume.h \
    costume/costumeselect.h \
    dragelem/categoryselect.h \
    dragelem/commandde.h \
    dragelem/dragableelement.h \
    dragelem/dragelemcategory.h \
    dragelem/dragelemlist.h \
    dragelem/hatde.h \
    dragelem/predicatede.h \
    dragelem/reporterde.h \
    dragelem/scriptdock.h \
    dragelem/wrapperde.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc


win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QScintilla/ -lqscintilla2
else:win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QScintilla/ -lqscintilla2
else:unix: LIBS += -L$$PWD/QScintilla/ -lqscintilla2

INCLUDEPATH += $$PWD/QScintilla \
    $$PWD/audio \
    $$PWD/costume \
    $$PWD/param \
    $$PWD/dragelem
DEPENDPATH += $$PWD/QScintilla \
    $$PWD/audio \
    $$PWD/costume \
    $$PWD/param \
    $$PWD/dragelem
