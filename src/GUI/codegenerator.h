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

    MainWindow* _Mainwindow;
    QMap<QString, QString> map;


};
#endif // CODEGENERATOR_H
