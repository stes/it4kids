#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include "costume/costume.h"
#include "param/param.h"
#include "codegenerator.h"
#include "sprite.h"
#include "mainwindow.h"

CodeGenerator::CodeGenerator(MainWindow * main)
{
    _Mainwindow = main;
    generateMap();
}

QString CodeGenerator::addQuotes(QString str)
{
    return '"' + str.toHtmlEscaped() + '"';
}

QString CodeGenerator::generateSprite(Sprite *sprite)
{
    QString str;
    _eventCounters.clear();
    _indentCounter = 1;

	QString costumeRegister;
	for (CostumeVector::const_iterator it = sprite->getCostumeVector()->begin(); it != sprite->getCostumeVector()->end(); it++)
	{
        costumeRegister += indentCode(&_snippets["costume_register"], 2)
            .replace("%entity%", "self")
            .replace("%name%", addQuotes((*it)->getName()))
            .replace("%file%", addQuotes((*it)->getFilename()));
	}

    // create class file
    str += indentCode(&_snippets["import"]);
    str += indentCode(&_snippets["class"]).replace("%name%", sprite->getName());
    str += indentCode(&_snippets["construct"], 1, costumeRegister);
    str += "%events%\n";

    // check every block for "header"-block
    DragElemVector *eleVec = sprite->getDragElemVector();
    for(DragElemVector::const_iterator elemIt = eleVec->begin(); elemIt != eleVec->end(); elemIt++)
    {
        if ((*elemIt)->getType() == "hat")
        {
            str += generateCode(*elemIt, 1) + '\n';
        }
    }

    // add Event registration
    QString events;
    for(QMap<QString, int>::const_iterator eventIt = _eventCounters.constBegin(); eventIt != _eventCounters.constEnd(); eventIt++)
    {
        for(int i = 1; i <= eventIt.value(); i++)
        {
            QString event = indent(2) + _events[eventIt.key()]._register + "\n";
            events += event.replace("%counter%", QString::number(i));
        }
    }

    str.replace("%events%", events);
    return str;
}

QString CodeGenerator::generateSprite(QString name)
{
    SpriteVector* spriteVec = _Mainwindow->getSpriteVector();

    for(SpriteVector::const_iterator it = spriteVec->begin(); it != spriteVec->end(); it++)
    {
        if((*it)->getName() == name)
        {
            return generateSprite(*it);
        }
    }

    return QString();
}

void CodeGenerator::generateFiles(QDir directory)
{
    SpriteVector* spriteVec = _Mainwindow->getSpriteVector();
    QString entityImport;
    QString entityReload;
    QString entityRegister;
	QString backgroundRegister;

    // sprites
    for(SpriteVector::const_iterator it = spriteVec->begin(); it != spriteVec->end(); it++)
    {
        entityImport += indentCode(&_snippets["entity_import"]).replace("%name%", (*it)->getName());
        entityReload += indentCode(&_snippets["entity_reload"], 1).replace("%name%", (*it)->getName());
        entityRegister += indentCode(&_snippets["entity_register"], 1).replace("%name%", (*it)->getName());

        // write to file
        QFile file(directory.filePath("sprite_" + (*it)->getName() + ".py"));
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << generateSprite(*it);
            file.close();
        }
    }

    CostumeVector* bgCostumeVec = _Mainwindow->getBackgroundSprite()->getCostumeVector();

    for (CostumeVector::const_iterator it = bgCostumeVec->begin(); it != bgCostumeVec->end(); it++)
	{
        backgroundRegister += indentCode(&_snippets["costume_register"], 1)
            .replace("%entity%", "background_ent")
            .replace("%name%", addQuotes((*it)->getName()))
            .replace("%file%", addQuotes((*it)->getFilename()));
	}

    // main file
    QString str;
    str += indentCode(&_snippets["main_import"]);
    str += entityImport + "\n";
    str += indentCode(&_snippets["main"], 0, backgroundRegister + entityReload + entityRegister);

    // write to file
    QFile file(directory.filePath("main.py"));
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << str;
        file.close();
    }
}

QString CodeGenerator::indentCode(QStringList *code, int num, QString content)
{
    QString str;
    for (QStringList::const_iterator it = code->constBegin(); it != code->constEnd(); it++)
    {
        if(*it == "%content%")
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

        // TODO: indent should be more dynamic
        QString tmp;
        if (next->getType() == "hat" && _events.contains(name))
        {
           tmp = indentCode(&_events[name]._code, sub, generateCode(next->getNextElem(), sub+1));
           if(_eventCounters.contains(name))
               _eventCounters[name]++;
           else
               _eventCounters[name] = 1;
           tmp.replace("%counter%", QString::number(_eventCounters[name]));
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

        std::vector<ParamBase*>* params =  next->getParamsVector();
        for(std::vector<ParamBase*>::const_iterator it = params->begin(); it != params->end(); it++)
        {
            tmp = tmp.arg((*it)->getValue());
        }

        str += tmp;
    }

    if(str.isEmpty())
    {
        str = indent(sub) + "pass\n";
    }

    return str;
}

QStringList CodeGenerator::processCodeField(QJsonArray Code)
{
    QStringList list;
    for (QJsonArray::const_iterator it = Code.constBegin(); it != Code.constEnd(); it++)
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

    for (QJsonArray::const_iterator it = Snippets.constBegin(); it != Snippets.constEnd(); it++)
    {
        QJsonObject Snippet = it->toObject();
        _snippets[Snippet["name"].toString()] = processCodeField(Snippet["code"].toArray());
    }

    for (QJsonArray::const_iterator it = Events.constBegin(); it != Events.constEnd(); it++)
    {
        QJsonObject Event = it->toObject();
        CodeGenerator::Event tmp = {processCodeField(Event["code"].toArray()), Event["register"].toString()};
        _events[Event["name"].toString()] = tmp;
    }

    for (QJsonArray::const_iterator it = Commands.constBegin(); it != Commands.constEnd(); it++)
    {
        QJsonObject Command = it->toObject();
        _commands[Command["name"].toString()] = processCodeField(Command["code"].toArray());
    }

    for (QJsonArray::const_iterator it = Controls.constBegin(); it != Controls.constEnd(); it++)
    {
        QJsonObject Control = it->toObject();
        _controls[Control["name"].toString()] = processCodeField(Control["code"].toArray());
    }
}
