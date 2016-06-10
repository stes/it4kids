#ifndef SAVELOADCLASS_H
#define SAVELOADCLASS_H

#include <QString>
#include <QJsonArray>

#include "dragelem/dragableelement.h"

class MainWindow;

class SaveLoadClass
{
public:
    SaveLoadClass() { }
    int loadScratch(const QString &path);
    void saveScratch(const QString &path);
private:
    //Scratch
    //load
    void handleScriptTuple(QJsonArray a, class Sprite *sprite);
    DragableElement* handleBlockTupleArray(QJsonArray a, class Sprite *sprite);
    DragableElement* handleBlockTuple(QJsonArray a, class Sprite *sprite);
    //save
    QJsonArray generateScriptTuple(DragableElement* element);
    QJsonArray generateBlockTupleArray(DragableElement* element);
    QJsonArray generateBlockTuple(DragableElement* element);
    //Snap
};

#endif // SAVELOADCLASS_H
