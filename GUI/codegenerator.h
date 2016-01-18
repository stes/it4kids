#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include "mainwindow.h"
#include "dragableelement.h"
#include "structs.h"
#include <QMap>

class CodeGenerator
{
public:
    CodeGenerator(MainWindow * main);
private:
    void generateFile();
    QString generateCode(DragableElement* element, int sub);
    ArgumentStruct* CodeGenerator::getCommand();
    QString dict(ArgumentStruct* argument);
    QString subident(int sub);

    MainWindow* _Mainwindow;
    QMap<QString, QString> map;


};
#endif // CODEGENERATOR_H
