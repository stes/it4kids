#ifndef SAVELOADCLASS_H
#define SAVELOADCLASS_H

#include <QString>
#include <QJsonArray>

#include "dragelem/dragableelement.h"

class MainWindow;

class SaveLoadClass
{
public:
    SaveLoadClass(MainWindow * main);
    int loadScratch(QString path);
    void saveScratch();
private:
    MainWindow* _Mainwindow;
    //Scratch
    //load
    void handleScriptTuple(QJsonArray a);
    DragableElement* handleBlockTuple(QJsonArray a);
    //save
    QJsonArray  generateScriptTuple(DragableElement* element);
    QJsonArray generateBlockTupleArray(DragableElement* element);
    QJsonArray generateBlockTuple(DragableElement* element);
    //Snap
};

#endif // SAVELOADCLASS_H
