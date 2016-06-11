#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

#include "saveloadclass.h"

#include "costume/costume.h"
#include "dragelem/draggableelement.h"
#include "param/param.h"
#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* sMainWindow;

bool SaveLoadClass::loadScratch(const QString &path, SpriteSelect *spriteSelect)
{
    QFile loadFile(path);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }
    QByteArray saveData = loadFile.readAll();

    QJsonDocument JDoc(QJsonDocument::fromJson(saveData));

    if (!JDoc.isArray())
    {
        qWarning("invalid file format");
        return false;
    }

    // clear the vector
    spriteSelect->clear();

    //get main object
    QJsonArray Main = JDoc.array();

    //get background Scripts
    QJsonArray::const_iterator it = Main.constBegin();
    for(QJsonArray::const_iterator it = Main.constBegin(); it != Main.constEnd(); it++)
    {
        if((*it).isObject())
        {
            QJsonObject JSprite = (*it).toObject();
            QString name = JSprite[QStringLiteral("objName")].toString();
            Sprite *sprite = new Sprite(name, sMainWindow);
            QJsonArray Scripts = JSprite[QStringLiteral("scripts")].toArray();
            for(QJsonArray::const_iterator scriptIt = Scripts.constBegin(); scriptIt != Scripts.constEnd(); scriptIt++)
                handleScriptTuple((*scriptIt).toArray(), sprite);

            Costume* costume = new Costume(sprite);
            costume->open("Assets/Costumes/dog2-a.png");
            costume->hide();
            sprite->setCurrentCostume(costume);
            spriteSelect->addSprite(sprite);
        }
    }

    return true;
}

void SaveLoadClass::handleScriptTuple(const QJsonArray &a, Sprite *sprite)
{
    if (a.count() != 3)
    {
        qWarning("invalid script tuple");
        return;
    }

    int x, y;
    QJsonArray BlockTuple;
    x = a[0].toInt();
    y = a[1].toInt();
    BlockTuple = a[2].toArray();
    //qDebug() << x << y << BlockTuple.count();

    DraggableElement *root = handleBlockTupleArray(BlockTuple, sprite);
    if(root)
    {
        root->move(QPoint(x, y));
        root->rearrangeLowerElems();
    }
}

DraggableElement* SaveLoadClass::handleBlockTupleArray(const QJsonArray &a, Sprite *sprite)
{
    DraggableElement* ele = 0;
    DraggableElement* lastEle = 0;

    for(QJsonArray::const_iterator it = a.constBegin(); it != a.constEnd(); it++)
    {
        ele = handleBlockTuple((*it).toArray(), sprite);

        if(lastEle)
            lastEle->getDock(ScriptDock::Lower)->dock(ele);
        lastEle = ele;
    }

    if(!ele)
        return 0;
    else
        return ele->getRoot();
}

DraggableElement* SaveLoadClass::handleBlockTuple(const QJsonArray &a, class Sprite *sprite)
{
    QString name = a[0].toString();
    DraggableElement* ele = sMainWindow->createNewElement(name, sprite);

    // params
    int i = 1;
    const std::vector<ParamBase*>* params = ele->getParamsVector();
    for(std::vector<ParamBase*>::const_iterator it = params->begin(); it != params->end() && i < a.count(); it++)
    {
        ParamBase::Type type = (*it)->getType();
        if(type == ParamBase::Number && a[i].isDouble())
            (*it)->setValue(QString::number(a[i].toDouble()));
        else if(type == ParamBase::String && a[i].isString())
            (*it)->setValue(a[i].toString());
        i++;
    }

    if(ele->getType() == DraggableElement::Wrapper && a.last().isArray())
    {
        DraggableElement *innerElem = handleBlockTupleArray(a.last().toArray(), sprite);
        if(innerElem)
            ele->getDock(ScriptDock::Inner)->dock(innerElem);
    }

    return ele;
}

bool SaveLoadClass::saveScratch(const QString &path, const SpriteSelect *spriteSelect)
{
    QJsonArray Main;

    //every sprite
    const SpriteVector *spriteVec = spriteSelect->getSpriteVector();
    for(SpriteVector::const_iterator it = spriteVec->begin(); it != spriteVec->end(); it++)
    {
        QJsonObject Sprite;
        Sprite.insert(QStringLiteral("objName"), QJsonValue((*it)->getName()));

        QJsonArray Scripts;
        const DragElemVector * eleVec = (*it)->getDragElemVector();
        for(DragElemVector::const_iterator elemIt = eleVec->begin(); elemIt != eleVec->end(); elemIt++)
        {
            if ((*elemIt)->getRoot() == (*elemIt))
            {
                 Scripts.append(generateScriptTuple(*elemIt));
            }
        }

        Sprite.insert(QStringLiteral("scripts"), Scripts);
        Main.append(Sprite);
    }
    QJsonDocument doc(Main);

    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }

    saveFile.write(doc.toJson(QJsonDocument::Compact));
    return true;
}

QJsonArray SaveLoadClass::generateScriptTuple(const DraggableElement* element)
{
    QPoint Pos = element->pos();
    QJsonArray ScriptTuple;
    ScriptTuple.append(QJsonValue(Pos.x()));
    ScriptTuple.append(QJsonValue(Pos.y()));
    ScriptTuple.append(generateBlockTupleArray(element));

    return ScriptTuple;
}

QJsonArray SaveLoadClass::generateBlockTupleArray(const DraggableElement* element)
{
    const DraggableElement* next = element;
    QJsonArray BlockArray;
    while (next)
    {
        BlockArray.append(generateBlockTuple(next));
        next = next->getNextElem();
    }
    return BlockArray;
}

QJsonArray SaveLoadClass::generateBlockTuple(const DraggableElement* element)
{
    QJsonArray Block;
    Block.append(QJsonValue(element->getIdentifier()));

    const std::vector<ParamBase*>* params = element->getParamsVector();
    for(std::vector<ParamBase*>::const_iterator it = params->begin(); it != params->end(); it++)
    {
        ParamBase::Type type = (*it)->getType();
        if(type == ParamBase::Number)
            Block.append(QJsonValue(((ParamBaseNum*)(*it))->getNumber()));
        else if(type == ParamBase::Number)
            Block.append(QJsonValue(((ParamBaseStr*)(*it))->getString()));
    }

    if (element->getWrapElem())
    {
        Block.append(generateBlockTupleArray(element->getWrapElem()));
    }

    return Block;
}

