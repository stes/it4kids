#include "saveloadclass.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

#include "sprite.h"
#include "mainwindow.h"

SaveLoadClass::SaveLoadClass(MainWindow * main)
{
    _Mainwindow = main;
}


int SaveLoadClass::loadScratch(QString path){

    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return 1;
    }
    QByteArray saveData = loadFile.readAll();

    QJsonDocument JDoc(QJsonDocument::fromJson(saveData));

    if (!JDoc.isObject())
    {
        qWarning("invalid file format");
        return 1;
    }

    //get main object
    QJsonObject Jmain = JDoc.object();

    //get background Scripts
    QJsonObject::iterator it = Jmain.find("scripts");
    if (it == Jmain.end() || !(*it).isArray())
        qWarning("invalid script section");

    QJsonArray ScriptArray = (*it).toArray();
    qDebug() << ScriptArray.count() << "scrips in Background found";
    for(QJsonArray::iterator it = ScriptArray.begin(); it != ScriptArray.end(); ++it)
    {
        if (it == ScriptArray.end() || !(*it).isArray())
            qWarning("invalid script");
        handleScriptTuple((*it).toArray());
    }

    return 0;
}

void SaveLoadClass::handleScriptTuple(QJsonArray a)
{
    if (a.count() != 3)
        qWarning("invalid script tuple");
    int x, y;
    QJsonArray BlockTuple;
    x = a[0].toInt();
    y = a[1].toInt();
    BlockTuple = a[2].toArray();
    qDebug() << x << y << BlockTuple.count();
 /*   DragableElement* ele;
    DragableElement* lastEle;
    DragableElement* hatEle;

    for(QJsonArray::iterator it = BlockTuple.begin(); it != BlockTuple.end(); ++it)
    {
        ele = handleBlockTuple((*it).toArray());
        //todo:for now all to curent sprite
        _Mainwindow->getCurrentSprite()->getDragElemVector()->push_back(ele);
        if (hatEle == (void*)0)
        {
            //set header
            hatEle = ele;
            ele->move(QPoint(x,y));
        }
        if (lastEle != (void*)0)
        {
            lastEle->setNextElem(ele);
        }
        lastEle = ele;
    }
    //erstelle
    */
}

DragableElement* SaveLoadClass::handleBlockTuple(QJsonArray a)
{
    QString name = a[0].toString();
    qDebug() << "hallo";
    //erstelle block
    DragableElement* ele = _Mainwindow->createNewElement(name);
   //work args

    qDebug() << a.count();
    qDebug() << a[0].toString();
    return ele;
}




void SaveLoadClass::saveScratch()
{
    SpriteVector* spriteVec = _Mainwindow->getSpriteVector();
    QJsonArray Script;

    //every sprite
    for(SpriteVector::iterator it = spriteVec->begin(); it != spriteVec->end(); ++it)
    {
        //every block in Sprite
        //check every block for "header"-Block
        DragElemVector * eleVec = (*it)->getDragElemVector();
        for(DragElemVector::iterator it2 = eleVec->begin(); it2 != eleVec->end(); ++it2)
        {
            //check every block for "header"-Block
            if ((*it2)->getType() == "hat")
            {
                 Script.append(generateScriptTuple(*it2));
            }
        }
    }
    QJsonDocument doc(Script);

    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
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
    while (next != (void*)0)
    {
        BlockArray.append(generateBlockTuple(next));

        next = next->getNextElem();
    }
    return BlockArray;
}

QJsonArray SaveLoadClass::generateBlockTuple(DragableElement*)
{
//    ArgumentStruct* argument = element->getArguments();
    QJsonArray Block;

/*    Block.append(QJsonValue(argument->name));

    //add parameter
    //todo: argument types!

    if (argument->nArgs == 1)
    {
        Block.append(QJsonValue(argument->arg1));
    }
    else   if (argument->nArgs == 2)
    {
        Block.append(QJsonValue(argument->arg1));
        Block.append(QJsonValue(argument->arg2));
    }
    else   if (argument->nArgs == 3)
    {
        Block.append(QJsonValue(argument->arg1));
        Block.append(QJsonValue(argument->arg2));
        Block.append(QJsonValue(argument->arg3));
    }
    else   if (argument->nArgs == 4)
    {
        Block.append(QJsonValue(argument->arg1));
        Block.append(QJsonValue(argument->arg2));
        Block.append(QJsonValue(argument->arg3));
        Block.append(QJsonValue(argument->arg4));
    }
    else   if (argument->nArgs == 5)
    {
        Block.append(QJsonValue(argument->arg1));
        Block.append(QJsonValue(argument->arg2));
        Block.append(QJsonValue(argument->arg3));
        Block.append(QJsonValue(argument->arg4));
        Block.append(QJsonValue(argument->arg5));
    }

    //caution C blocks
    if (element->getWrapElem() != (void*)0)
    {
        Block.append(generateBlockTupleArray(element->getWrapElem()));
    }*/

    return Block;
}

