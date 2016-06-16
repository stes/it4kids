#ifndef SAVELOADCLASS_H
#define SAVELOADCLASS_H

#include <QString>
#include <QJsonArray>

class DraggableElement;
class Sprite;
class SpriteSelect;
class QWidget;

class SaveLoadClass
{
	QWidget* _elemParent;
	std::vector<DraggableElement*> _LoadableElems;

public:
    SaveLoadClass(QWidget *elemParent) : _elemParent(elemParent) { }
    bool loadScratch(const QString &path, SpriteSelect *spriteSelect);
    bool saveScratch(const QString &path, const SpriteSelect *spriteSelect);

	void registerElement(DraggableElement* element);

private:
    DraggableElement* createElement(const QString &ident, Sprite *sprite);

    //Scratch
    //load
    void handleScriptTuple(const QJsonArray &a, Sprite *sprite);
    DraggableElement* handleBlockTupleArray(const QJsonArray &a, Sprite *sprite);
    DraggableElement* handleBlockTuple(const QJsonArray &a, Sprite *sprite);
    //save
    QJsonArray generateScriptTuple(const DraggableElement* element);
    QJsonArray generateBlockTupleArray(const DraggableElement* element);
    QJsonArray generateBlockTuple(const DraggableElement* element);
    //Snap
};

#endif // SAVELOADCLASS_H
