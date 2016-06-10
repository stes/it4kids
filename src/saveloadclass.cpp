#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

#include "saveloadclass.h"

#include "costume/costume.h"
#include "param/param.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

int SaveLoadClass::loadScratch(const QString &path)
{

    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return 1;
    }
    QByteArray saveData = loadFile.readAll();

    QJsonDocument JDoc(QJsonDocument::fromJson(saveData));

    if (!JDoc.isArray())
    {
        qWarning("invalid file format");
        return 1;
    }

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
            sMainWindow->addSprite(sprite);
        }
    }

    return 0;
}

void SaveLoadClass::handleScriptTuple(QJsonArray a, Sprite *sprite)
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

    DragableElement *root = handleBlockTupleArray(BlockTuple, sprite);
    if(root)
    {
        root->move(QPoint(x, y));
        root->rearrangeLowerElems();
    }
}

DragableElement* SaveLoadClass::handleBlockTupleArray(QJsonArray a, Sprite *sprite)
{
    DragableElement* ele = 0;
    DragableElement* lastEle = 0;

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

DragableElement* SaveLoadClass::handleBlockTuple(QJsonArray a, class Sprite *sprite)
{
    QString name = a[0].toString();
    DragableElement* ele = sMainWindow->createNewElement(name, sprite);

    // params
    int i = 1;
    std::vector<ParamBase*>* params =  ele->getParamsVector();
    for(std::vector<ParamBase*>::iterator it = params->begin(); it != params->end() && i < a.count(); it++)
    {
        ParamBase::Type type = (*it)->getType();
        if(type == ParamBase::Number && a[i].isDouble())
            (*it)->setValue(QString::number(a[i].toDouble()));
        else if(type == ParamBase::String && a[i].isString())
            (*it)->setValue(a[i].toString());
        i++;
    }

    if(ele->getType() == DragableElement::Wrapper && a.last().isArray())
    {
        DragableElement *innerElem = handleBlockTupleArray(a.last().toArray(), sprite);
        if(innerElem)
            ele->getDock(ScriptDock::Inner)->dock(innerElem);
    }

    return ele;
}

void SaveLoadClass::saveScratch(const QString &path)
{
    SpriteVector* spriteVec = sMainWindow->getSpriteVector();
    QJsonArray Main;

    //every sprite
    for(SpriteVector::const_iterator it = spriteVec->begin(); it != spriteVec->end(); it++)
    {
        QJsonObject Sprite;
        Sprite.insert(QStringLiteral("objName"), QJsonValue((*it)->getName()));

        QJsonArray Scripts;
        DragElemVector * eleVec = (*it)->getDragElemVector();
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
        return;
    }

    saveFile.write(doc.toJson());
}

QJsonArray SaveLoadClass::generateScriptTuple(DragableElement* element)
{
    QPoint Pos = element->pos();
    QJsonArray ScriptTuple;
    ScriptTuple.append(QJsonValue(Pos.x()));
    ScriptTuple.append(QJsonValue(Pos.y()));
    ScriptTuple.append(generateBlockTupleArray(element));

    return ScriptTuple;
}

QJsonArray SaveLoadClass::generateBlockTupleArray(DragableElement* element)
{
    DragableElement* next = element;
    QJsonArray BlockArray;
    while (next)
    {
        BlockArray.append(generateBlockTuple(next));
        next = next->getNextElem();
    }
    return BlockArray;
}

QJsonArray SaveLoadClass::generateBlockTuple(DragableElement* element)
{
    QJsonArray Block;
    Block.append(QJsonValue(element->getIdentifier()));

    std::vector<ParamBase*>* params =  element->getParamsVector();
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

