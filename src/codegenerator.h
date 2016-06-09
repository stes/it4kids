#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <QMap>
#include <QDir>

#include "dragelem/dragableelement.h"

class MainWindow;

class CodeGenerator
{
public:
    CodeGenerator();
    QString generateSprite(Sprite *sprite);
    QString generateSprite(QString name);
    void generateFiles(QDir directory);

    bool supported(QString ident);

private:
    struct Event
    {
        QStringList _code;
        QString _register;
    };

    QString addQuotes(QString str);

    QString generateCode(DragableElement* element, int sub);
    QString indent(int indent);
    QString indentCode(QStringList *code, int indent = 0, QString content = "");

    QStringList processCodeField(QJsonArray Code);
    void generateMap();

    int _indentCounter;
    QMap<QString, int> _eventCounters;

    QMap<QString, QStringList> _snippets;
    QMap<QString, Event> _events;
    QMap<QString, QStringList> _commands;
    QMap<QString, QStringList> _controls;
};
#endif // CODEGENERATOR_H
