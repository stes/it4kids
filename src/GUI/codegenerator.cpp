#include "codegenerator.h"
#include "sprite.h"
#include "mainwindow.h"
#include "param/param.h"
#include <qfile.h>

CodeGenerator::CodeGenerator(MainWindow * main)
{
    _Mainwindow = main;
    generateMap();
}

void CodeGenerator::generateFile()
{
    QString str = "";
    _eventCounters.clear();
    _eventList = "";

    SpriteVector* spriteVec = _Mainwindow->getSpriteVector();

    str += readMap("$import");

    //every Sprite
    for(SpriteVector::iterator it = spriteVec->begin(); it != spriteVec->end(); ++it)
    {
        //create class file
        str += "class " + (*it)->getName() + "(it4k.Entity):\n\n";

        str += readMap("$construct");

        //check every block for "header"-Block
        DragElemVector * eleVec = (*it)->getDragElemVector();
        for(DragElemVector::iterator it2 = eleVec->begin(); it2 != eleVec->end(); ++it2)
        {
            //prüfe ob start Command
            if ((*it2)->getType() == "hat")
            {
                str += generateCode(*it2,1);
                //generateCode(*it2,0);
                //qDebug() << generateCode(*it2,0);
            }
        }

        str += "\n" + readMap("$append");

        str += "\n";
    }

    // add Event registration %definition%
    str.replace("%definition%", _eventList);

    //write to file
    QFile file("python/out.py");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << str;

    file.close();
}


QString CodeGenerator::generateCode(DragableElement* element, int sub)
{
    QString ret = "";
    //int sublvl = sub;
    for(DragableElement* next = element; next; next = next->getNextElem())
    {
        //add command
        ret += subident(sub) + dict(next) + "\n";

        //add sub Command, if exists
        if (next->getWrapElem())
        {
             ret += generateCode(next->getWrapElem(),sub+1); //todo dict start und end
        }
    }
    return ret;
}

//einrückungen etc.
QString CodeGenerator::subident(int sub)
{
    QString str ="";
    for (int i = 0; i<sub;i++)
    {
        str += readMap("$tab");
    }
    return str;
}

//translate ccommand in reqired language
//uses special commands :start, end, tab
QString CodeGenerator::dict(DragableElement* element)
{
    QString str;
    QString name = element->getIdentifier();
    int type = element->getType() == "hat";
    if (map.contains(name))
    {
       if (!type)
           str += subident(1);
       str += map[name];
       //if event add event number
       QString eventType;
       if (name == "receiveGo")
           eventType = "on_start";
       else if (name == "receiveKey" || name == "receiveInteraction" || name == "receiveMessage")
           eventType = "on_click";

       if(!eventType.isEmpty())
       {
           if(_eventCounters.contains(name))
               _eventCounters[name]++;
           else
               _eventCounters[name] = 1;
          str = str.arg(_eventCounters[name]);
          _eventList += subident(2) + "self.register(" + eventType + "=self." + name + QString::number(_eventCounters[name]) + ")\n";
       }
    }
    else
    {
        qDebug() << "block: " << name << "not supported yet";
        str = subident(1) + "printf(\"" + name + " nicht verfügbar\")";
    }

    std::vector<Param*>* params =  element->getParamsVector();
    for(std::vector<Param*>::iterator it = params->begin(); it != params->end(); it++)
    {
        str = str.arg((*it)->getValue());
    }

    return str;
}

void CodeGenerator::generateMap()
{
    QFile file(":in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not load Python file";
        return;
    }
    int n = 0;
    int err = 0;
    int coment = 0;

    while (!file.atEnd()) {
        QString line = file.readLine();
        if (line[0] == '/' && line[1] == '/'){
            n++;
            coment++;
            continue;
        }

        line.replace("\n","");
        line.replace("\\n", "\n");

        QStringList list = line.split("@@",QString::SkipEmptyParts);

        if (list.length() == 2)
        {
            map.insert(list[0], list[1]);

        }
        else
        {
            qDebug() << "invalid command line: " << line;
            err++;
        }
        n++;
    }
    qDebug() << n-err << "/" << n << "lines loaded (" << coment << "comments)";
}

QString CodeGenerator::readMap(QString arg)
{
    if (map.contains(arg))
    {
        return map[arg];
    }
    return "";
}
