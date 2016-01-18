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
    GUI/mainwindow.cpp \
    GUI/scene.cpp \
    GUI/scriptarea.cpp \
    GUI/dockingarea.cpp \
    GUI/spriteselect.cpp \
    GUI/sprite.cpp \
    GUI/param/paramclone.cpp \
    GUI/param/paramcolor.cpp \
    GUI/param/paramcostume.cpp \
    GUI/param/paramdelim.cpp \
    GUI/param/paramdestination.cpp \
    GUI/param/paramdirection.cpp \
    GUI/param/paramdock.cpp \
    GUI/param/parameffect.cpp \
    GUI/param/paraminteraction.cpp \
    GUI/param/paramjoinwords.cpp \
    GUI/param/paramkey.cpp \
    GUI/param/paramlistid.cpp \
    GUI/param/paramlistselec.cpp \
    GUI/param/parammath.cpp \
    GUI/param/parammessage.cpp \
    GUI/param/paramnumber.cpp \
    GUI/param/paramsound.cpp \
    GUI/param/paramstopchoices.cpp \
    GUI/param/paramstring.cpp \
    GUI/param/paramtouch.cpp \
    GUI/param/paramtype.cpp \
    GUI/param/paramvariables.cpp \
    GUI/audio/audioengine.cpp \
    GUI/audio/wavfile.cpp \
    GUI/audio/soundselect.cpp \
    GUI/costume/costume.cpp \
    GUI/costume/costumeselect.cpp \
    GUI/dragelem/categoryselect.cpp \
    GUI/dragelem/commandde.cpp \
    GUI/dragelem/dragableelement.cpp \
    GUI/dragelem/dragelemcategory.cpp \
    GUI/dragelem/dragelemlist.cpp \
    GUI/dragelem/hatde.cpp \
    GUI/dragelem/predicatede.cpp \
    GUI/dragelem/reporterde.cpp \
    GUI/dragelem/scriptdock.cpp \
    GUI/dragelem/wrapperde.cpp \
    GUI/teacher/studentlist.cpp

HEADERS  += GUI/mainwindow.h \
    GUI/scene.h \
    GUI/scriptarea.h \
    GUI/dockingarea.h \
    GUI/scriptdock.h \
    GUI/spriteselect.h \
    GUI/sprite.h \
    GUI/param/param.h \
    GUI/param/paramclone.h \
    GUI/param/paramcolor.h \
    GUI/param/paramcostume.h \
    GUI/param/paramdelim.h \
    GUI/param/paramdestination.h \
    GUI/param/paramdirection.h \
    GUI/param/paramdock.h \
    GUI/param/parameffect.h \
    GUI/param/paraminteraction.h \
    GUI/param/paramjoinwords.h \
    GUI/param/paramkey.h \
    GUI/param/paramlistid.h \
    GUI/param/paramlistselec.h \
    GUI/param/parammath.h \
    GUI/param/parammessage.h \
    GUI/param/paramnumber.h \
    GUI/param/paramsound.h \
    GUI/param/paramstopchoices.h \
    GUI/param/paramstring.h \
    GUI/param/paramtouch.h \
    GUI/param/paramtype.h \
    GUI/param/paramvariables.h \
    GUI/audio/audioengine.h \
    GUI/audio/wavfile.h \
    GUI/audio/soundselect.h \
    GUI/costume/costume.h \
    GUI/costume/costumeselect.h \
    GUI/dragelem/categoryselect.h \
    GUI/dragelem/commandde.h \
    GUI/dragelem/dragableelement.h \
    GUI/dragelem/dragelemcategory.h \
    GUI/dragelem/dragelemlist.h \
    GUI/dragelem/hatde.h \
    GUI/dragelem/predicatede.h \
    GUI/dragelem/reporterde.h \
    GUI/dragelem/scriptdock.h \
    GUI/dragelem/wrapperde.h \
    GUI/teacher/studentlist.h

FORMS    += GUI/mainwindow.ui

DISTFILES +=

RESOURCES += \
    GUI/resources.qrc


win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/GUI/QScintilla/ -lqscintilla2
else:win32:CONFIG(release, debug|release): LIBS += -L$$PW/DGUI/QScintilla/ -lqscintilla2
else:unix: LIBS += -L$$PWD/GUI/QScintilla/ -lqscintilla2

INCLUDEPATH += $$PWD/GUI/QScintilla \
    $$PWD/GUI/audio \
    $$PWD/GUI/costume \
    $$PWD/GUI/param \
    $$PWD/GUI/dragelem \
    $$PWD/GUI/teacher
DEPENDPATH += $$PWD/QScintilla \
    $$PWD/GUI/audio \
    $$PWD/GUI/costume \
    $$PWD/GUI/param \
    $$PWD/GUI/dragelem \
    $$PWD/GUI/teacher
