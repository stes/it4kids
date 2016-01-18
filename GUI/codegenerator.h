#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include "mainwindow.h"
#include "dragableelement.h"
#include "structs.h"

class CodeGenerator
{
public:
    CodeGenerator(MainWindow * main);
private:
    void generateFile();
    QString generateCode(DragableElement* element, int sub);
    ArgumentStruct* CodeGenerator::getCommand();
    QString dict(ArgumentStruct* argument);
    MainWindow* _Mainwindow;


};
#endif // CODEGENERATOR_H
