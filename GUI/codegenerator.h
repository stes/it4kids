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
    ArgumentStruct* CodeGenerator::getCommand();
    QString dict(ArgumentStruct* argument);
    QString subident(int sub);
    void generateMap();

    MainWindow* _Mainwindow;
    QMap<QString, QString> map;


};
#endif // CODEGENERATOR_H
