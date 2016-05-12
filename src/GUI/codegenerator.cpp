#include "codegenerator.h"
#include "sprite.h"
#include "mainwindow.h"
#include <qfile.h>

CodeGenerator::CodeGenerator(MainWindow * main)
{
    _Mainwindow = main;
    generateMap();
}

void CodeGenerator::generateFile(){
    QString str = "";
    _eventList = "";
    _eventReceiveGo = 0;
    _eventReceiveKey = 0;
    _eventReceiveInteraction = 0;
    _eventReceiveMessage = 0;

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

    // add Event refistration %definition%
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
    DragableElement* next = element;
    QString ret = "";
    ArgumentStruct* argument;
    //int sublvl = sub;
    while (next)
    {
        //add command
        argument = next->getArguments();
        ret += subident(sub) + dict(argument) + "\n";

        //add sub Command, if exists
        if (next->getWrapElem())
        {
             ret += generateCode(next->getWrapElem(),sub+1); //todo dict start und end
        }

        next = next->getNextElem();
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
QString CodeGenerator::dict(ArgumentStruct* argument)
{
    QString str;
    if (map.contains(argument->name))
    {
       if (!argument->type)
           str += subident(1);
       str += map[argument->name];
       //if event add event number
       if (argument->name == "receiveGo")
       {
           _eventReceiveGo++;
          str.replace("%1",QString::number(_eventReceiveGo));
          _eventList += subident(2) + "self.register(on_start=self.receiveGO" + QString::number(_eventReceiveGo) + ")\n";
       } else if(argument->name == "receiveKey")
       {
           _eventReceiveKey++;
          str.replace("%1",QString::number(_eventReceiveKey));
          _eventList += subident(2) + "self.register(on_click=self.receiveKey" + QString::number(_eventReceiveKey) + ")\n";
       }else if(argument->name == "receiveInteraction")
       {
           _eventReceiveInteraction++;
          str.replace("%1",QString::number(_eventReceiveInteraction));
          _eventList += subident(2) + "self.register(on_click=self.receiveInteraction" + QString::number(_eventReceiveInteraction) + ")\n";
       }
       else if(argument->name == "receiveMessage")
       {
           _eventReceiveMessage++;
          str.replace("%1",QString::number(_eventReceiveMessage));
          _eventList += subident(2) + "self.register(on_click=self.receiveMessage" + QString::number(_eventReceiveMessage) + ")\n";
       }
    }else{
        qDebug() << "block: " << argument->name << "not supported yet";
        str = subident(1) + "printf(\"" + argument->name + " nicht verfügbar\")";
    }

    str.replace("%1",argument->arg1);
    str.replace("%2",argument->arg2);
    str.replace("%3",argument->arg3);
    str.replace("%4",argument->arg4);
    str.replace("%5",argument->arg5);

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
