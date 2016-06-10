#ifndef SAVELOADCLASS_H
#define SAVELOADCLASS_H

#include <QString>
#include <QJsonArray>

#include "dragelem/draggableelement.h"

class MainWindow;

class SaveLoadClass
{
public:
    SaveLoadClass() { }
    bool loadScratch(const QString &path, std::vector<Sprite*> *spriteVec);
    bool saveScratch(const QString &path, std::vector<Sprite*> *spriteVec);
private:
    //Scratch
    //load
    void handleScriptTuple(QJsonArray a, class Sprite *sprite);
    DraggableElement* handleBlockTupleArray(QJsonArray a, class Sprite *sprite);
    DraggableElement* handleBlockTuple(QJsonArray a, class Sprite *sprite);
    //save
    QJsonArray generateScriptTuple(DraggableElement* element);
    QJsonArray generateBlockTupleArray(DraggableElement* element);
    QJsonArray generateBlockTuple(DraggableElement* element);
    //Snap
};

#endif // SAVELOADCLASS_H
