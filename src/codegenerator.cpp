#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "codegenerator.h"

#include "costume/costume.h"
#include "dragelem/draggableelement.h"
#include "param/param.h"
#include "sprite.h"


CodeGenerator::CodeGenerator()
{
    generateMap();
}

QString CodeGenerator::addQuotes(const QString &str)
{
    return '"' + str.toHtmlEscaped() + '"';
}

QString CodeGenerator::generateSprite(const Sprite *sprite, bool stage)
{
    QString str;
    _eventCounters.clear();
    _indentCounter = 1;

    QStringList *costumeRegSnippet = &_snippets["costume_register"];
    QStringList *constructSnippet = stage ? &_snippets["construct_stage"] : &_snippets["construct"];

    QString costumeRegister;
    for (CostumeVector::const_iterator it = sprite->getCostumeVector()->begin(); it != sprite->getCostumeVector()->end(); it++)
    {
        costumeRegister += indentCode(costumeRegSnippet, 2)
            .replace(QLatin1String("%entity%"), QLatin1String("self"))
            .replace(QLatin1String("%name%"), addQuotes((*it)->getName()))
            .replace(QLatin1String("%file%"), addQuotes((*it)->getFilename()));
    }

    // create class file
    str += indentCode(&_snippets["import"]);
    str += indentCode(&_snippets["class"]).replace(QLatin1String("%name%"), sprite->getName());
    str += indentCode(constructSnippet, 1, costumeRegister);
    str += "%events%\n";

    // check every block for "header"-block
    const DragElemVector *eleVec = sprite->getDragElemVector();
    for(DragElemVector::const_iterator elemIt = eleVec->begin(); elemIt != eleVec->end(); elemIt++)
    {
        if ((*elemIt)->getType() == DraggableElement::Hat)
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
            events += event.replace(QLatin1String("%counter%"), QString::number(i));
        }
    }

    str.replace(QLatin1String("%events%"), events);
    return str;
}

QString CodeGenerator::generateMain(const Sprite *bgSprite, const SpriteVector *spriteVec)
{
    QString entityImport;
    QString entityRegister;

    QStringList *entImpSnippet = &_snippets["entity_import"];
    QStringList *entRegSnippet = &_snippets["entity_register"];

    entityImport += indentCode(entImpSnippet).replace(QLatin1String("%name%"), bgSprite->getName());
    entityRegister += indentCode(entRegSnippet, 1).replace(QLatin1String("%name%"), bgSprite->getName());

    // sprites
    for(SpriteVector::const_iterator it = spriteVec->begin(); it != spriteVec->end(); it++)
    {
        entityImport += indentCode(entImpSnippet).replace(QLatin1String("%name%"), (*it)->getName());
        entityRegister += indentCode(entRegSnippet, 1).replace(QLatin1String("%name%"), (*it)->getName());
    }

    // main file
    QString str;
    str += indentCode(&_snippets["main_import"]);
    str += entityImport + "\n";
    str += indentCode(&_snippets["main"], 0, entityRegister);

    return str;
}

void CodeGenerator::generateAllFiles(const QDir &directory, const Sprite *bgSprite, const SpriteVector *spriteVec)
{
    generateSpriteFile(directory, bgSprite, true);

    for(SpriteVector::const_iterator it = spriteVec->begin(); it != spriteVec->end(); it++)
        generateSpriteFile(directory, *it);

    generateMainFile(directory, bgSprite, spriteVec);
}

void CodeGenerator::generateSpriteFile(const QDir &directory, const Sprite *sprite, bool stage)
{
    // TODO: prefix for stage
    writeToFile(directory.filePath("sprite_" + sprite->getName() + ".py"), generateSprite(sprite, stage));
}

void CodeGenerator::generateMainFile(const QDir &directory, const Sprite *bgSprite, const SpriteVector *spriteVec)
{
    writeToFile(directory.filePath(QStringLiteral("main.py")), generateMain(bgSprite, spriteVec));
}

void CodeGenerator::writeToFile(const QString &path, const QString &data)
{
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << data;
        file.close();
    }
}

QString CodeGenerator::indentCode(const QStringList *code, int num, const QString &content)
{
    QString str;
    for (QStringList::const_iterator it = code->constBegin(); it != code->constEnd(); it++)
    {
        if(*it == QLatin1String("%content%"))
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

QString CodeGenerator::generateCode(const DraggableElement* element, int sub)
{
    QString str;
    bool stop = false;

    for(const DraggableElement* next = element; next && !stop; next = next->getNextElem())
    {
        QString name = next->getIdentifier();

        // TODO: indent should be more dynamic
        QString tmp;
        if (next->getType() == DraggableElement::Hat && _events.contains(name))
        {
           tmp = indentCode(&_events[name]._code, sub, generateCode(next->getNextElem(), sub+1));
           if(_eventCounters.contains(name))
               _eventCounters[name]++;
           else
               _eventCounters[name] = 1;
           tmp.replace(QLatin1String("%counter%"), QString::number(_eventCounters[name]));
           stop = true;
        }
        else if (next->getType() == DraggableElement::Wrapper && _controls.contains(name))
        {
            tmp = indentCode(&_controls[name], sub, generateCode(next->getWrapElem(), sub+1));
        }
        else if (next->getType() == DraggableElement::Command && _commands.contains(name))
        {
            tmp = indentCode(&_commands[name], sub);
        }
        else
        {
            qDebug() << "block: " << name << "not supported yet";
            str += indent(sub) + "pass\n";
            continue;
        }

        if(tmp.contains(QLatin1String("%indent_counter%")))
        {
            tmp.replace(QLatin1String("%indent_counter%"), QString::number(_indentCounter));
            _indentCounter++;
        }

        const std::vector<ParamBase*>* params = next->getParamsVector();
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

bool CodeGenerator::supported(const QString &ident)
{
    return _events.contains(ident) || _controls.contains(ident) || _commands.contains(ident);
}

QStringList CodeGenerator::processCodeField(const QJsonArray &Code)
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
