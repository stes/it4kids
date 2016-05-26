#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include "codegenerator.h"
#include "sprite.h"
#include "mainwindow.h"
#include "param/param.h"

CodeGenerator::CodeGenerator(MainWindow * main)
{
    _Mainwindow = main;
    generateMap();
}

void CodeGenerator::generateFile()
{
    QString str;
    _eventCounters.clear();

    SpriteVector* spriteVec = _Mainwindow->getSpriteVector();

    str += indentCode(&_snippets["import"]);

    //every Sprite
    for(SpriteVector::iterator it = spriteVec->begin(); it != spriteVec->end(); ++it)
    {
        _eventList.clear();
        _indentCounter = 1;
        //create class file
        str += indentCode(&_snippets["class"]).replace("%name%", (*it)->getName());
        str += indentCode(&_snippets["construct"], 1);
        str += "%events%\n";

        //check every block for "header"-Block
        DragElemVector * eleVec = (*it)->getDragElemVector();
        for(DragElemVector::iterator it2 = eleVec->begin(); it2 != eleVec->end(); ++it2)
        {
            //prüfe ob start Command
            if ((*it2)->getType() == "hat")
            {
                str += generateCode(*it2, 1) + '\n';
            }
        }

        // add Event registration %definition%
        str.replace("%events%", indentCode(&_eventList, 2));
    }

    str += "\n" + indentCode(&_snippets["append"]) + "\n";

    //write to file
    QFile file("python/out.py");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << str;

    file.close();
}

QString CodeGenerator::indentCode(QStringList *code, int num, QString content)
{
    QString str;
    for (QStringList::const_iterator it = code->constBegin(); it != code->constEnd(); it++)
    {
        if(*it == "%content%" && !content.isEmpty())
            str += content;
        else
            str += indent(num) + *it + '\n';
    }
    return str;
}

QString CodeGenerator::indent(int indent)
{
    QString str;
    return str.fill(' ', indent * 4);
}

QString CodeGenerator::generateCode(DragableElement* element, int sub)
{
    QString str;
    bool stop = false;

    for(DragableElement* next = element; next && !stop; next = next->getNextElem())
    {
        QString name = next->getIdentifier();

        QString tmp;
        if (next->getType() == "hat" && _events.contains(name))
        {
           tmp = indentCode(&_events[name]._code, sub, generateCode(next->getNextElem(), sub+1));
           if(_eventCounters.contains(name))
               _eventCounters[name]++;
           else
               _eventCounters[name] = 1;
           QString num = QString::number(_eventCounters[name]);
           tmp.replace("%counter%", num);
           QString event = _events[name]._register;
           _eventList << event.replace("%counter%", num);
           stop = true;
        }
        else if (next->getType() == "wrapper" && _controls.contains(name))
        {
            tmp = indentCode(&_controls[name], sub, generateCode(next->getWrapElem(), sub+1));
        }
        else if (next->getType() == "command" && _commands.contains(name))
        {
            tmp = indentCode(&_commands[name], sub);
        }
        else
        {
            qDebug() << "block: " << name << "not supported yet";
            tmp = indent(sub) + "pass\n";
        }

        if(tmp.contains("%indent_counter%"))
        {
            tmp.replace("%indent_counter%", QString::number(_indentCounter));
            _indentCounter++;
        }

        std::vector<Param*>* params =  next->getParamsVector();
        for(std::vector<Param*>::iterator it = params->begin(); it != params->end(); it++)
        {
            tmp = tmp.arg((*it)->getValue());
        }

        str += tmp;
    }

    return str;
}

QStringList CodeGenerator::processCodeField(QJsonArray Code)
{
    QStringList list;
    for (QJsonArray::iterator it = Code.begin(); it != Code.end(); it++)
    {
        list += it->toString();
    }
    return list;
}

void CodeGenerator::generateMap()
{
    QFile codeFile(":code.json");
    if (!codeFile.open(QIODevice::ReadOnly))
    {
        qWarning("Could not open code file");
        return;
    }
    QByteArray codeData = codeFile.readAll();

    QJsonDocument JDoc(QJsonDocument::fromJson(codeData));
    if (!JDoc.isObject())
    {
        qWarning("Code file: invalid file format");
        return;
    }

    QJsonObject Main = JDoc.object();
    QJsonArray Snippets = Main["snippets"].toArray();
    QJsonArray Events = Main["events"].toArray();
    QJsonArray Commands = Main["commands"].toArray();
    QJsonArray Controls = Main["controls"].toArray();

    for (QJsonArray::iterator it = Snippets.begin(); it != Snippets.end(); it++)
    {
        QJsonObject Snippet = it->toObject();
        _snippets[Snippet["name"].toString()] = processCodeField(Snippet["code"].toArray());
    }

    for (QJsonArray::iterator it = Events.begin(); it != Events.end(); it++)
    {
        QJsonObject Event = it->toObject();
        _events[Event["name"].toString()] = {processCodeField(Event["code"].toArray()), Event["register"].toString()};
    }

    for (QJsonArray::iterator it = Commands.begin(); it != Commands.end(); it++)
    {
        QJsonObject Command = it->toObject();
        _commands[Command["name"].toString()] = processCodeField(Command["code"].toArray());
    }

    for (QJsonArray::iterator it = Controls.begin(); it != Controls.end(); it++)
    {
        QJsonObject Control = it->toObject();
        _controls[Control["name"].toString()] = processCodeField(Control["code"].toArray());
    }
}
