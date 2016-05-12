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
    QString generateCode(DragableElement* element, int sub);
    QString dict(DragableElement* element);
    QString subident(int sub);
    void generateMap();
    QString readMap(QString arg);
    //quick and dirty, rehandelt with Block generation from code
    QString _eventList = "";
    QMap<QString, int> _eventCounters;

    MainWindow* _Mainwindow;
    QMap<QString, QString> map;


};
#endif // CODEGENERATOR_H
