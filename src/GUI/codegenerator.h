#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include "dragableelement.h"
#include "structs.h"
#include <QMap>

class MainWindow;

class CodeGenerator
{
public:
    CodeGenerator(MainWindow * main);
    void generateFile();
private:
    QString generateCode(DragableElement* element, int sub);
    QString dict(ArgumentStruct* argument);
    QString subident(int sub);
    void generateMap();
    QString readMap(QString arg);
    //quick and dirty, rehandelt with Block generation from code
    QString _eventList = "";
    int _eventReceiveGo = 0;
    int _eventReceiveKey = 0;
    int _eventReceiveInteraction = 0;
    int _eventReceiveMessage = 0;

    MainWindow* _Mainwindow;
    QMap<QString, QString> map;


};
#endif // CODEGENERATOR_H
