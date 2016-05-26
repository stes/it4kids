#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include "dragableelement.h"
#include <QMap>

class MainWindow;

class CodeGenerator
{
public:
    CodeGenerator(MainWindow * main);
    void generateFile();
private:
    struct Event
    {
        QStringList _code;
        QString _register;
    };

    QStringList processCodeField(QJsonArray Code);
    QString generateCode(DragableElement* element, int sub);
    QString indent(int indent);
    QString indentCode(QStringList *code, int indent = 0, QString content = "");
    void generateMap();
    //quick and dirty, rehandelt with Block generation from code
    QStringList _eventList;
    int _indentCounter;
    QMap<QString, int> _eventCounters;

    MainWindow* _Mainwindow;
    QMap<QString, QStringList> _snippets;
    QMap<QString, Event> _events;
    QMap<QString, QStringList> _commands;
    QMap<QString, QStringList> _controls;
};
#endif // CODEGENERATOR_H
