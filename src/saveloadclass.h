#ifndef SAVELOADCLASS_H
#define SAVELOADCLASS_H

#include <QString>
#include <QJsonArray>

class DraggableElement;
class SpriteSelect;

class SaveLoadClass
{
public:
    SaveLoadClass() { }
    bool loadScratch(const QString &path, SpriteSelect *spriteSelect);
    bool saveScratch(const QString &path, const SpriteSelect *spriteSelect);
private:
    //Scratch
    //load
    void handleScriptTuple(const QJsonArray &a, class Sprite *sprite);
    DraggableElement* handleBlockTupleArray(const QJsonArray &a, class Sprite *sprite);
    DraggableElement* handleBlockTuple(const QJsonArray &a, class Sprite *sprite);
    //save
    QJsonArray generateScriptTuple(const DraggableElement* element);
    QJsonArray generateBlockTupleArray(const DraggableElement* element);
    QJsonArray generateBlockTuple(const DraggableElement* element);
    //Snap
};

#endif // SAVELOADCLASS_H
