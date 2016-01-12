#include "codegenerator.h"


CodeGenerator::CodeGenerator(MainWindow * main)
{
    _Mainwindow = main;
}

void CodeGenerator::generateFile(){
    //Per Figure
    for (QObject &element : _Mainwindow.children())
    {
        if (element->isWidgetType())
        {
           QMetaObject meta = element->metaObject();
           qDebug() << meta.className();
           //todo chek if Block, else return
           //receiveGo receiveKey receiveInteraction receiveMessage define start Kommands
           if ((element->_text == "receiveGo") or (element->_text == "receiveKey") or (element->_text == "receiveInteraction") or (element->_text =="receiveMessage"))
           {
                Qstring s = generateCode(element);
           }
        }
    }
}


Qstring CodeGenerator::generateCode(DragableElement* element, int sub)
{
    DragableElement* next = element;
        QString ret = "";
        ArgumentStruct* argument;
        //int sublvl = sub;
        while (next != null)
        {
            //add command
            argument = next.getCommand();
            ret += subident(sublvl) + dict(argument) + "\n";


            //add sub Command
            if (next.getSub != Null) //only if exists
            {
                ret += dict("start") + buildComands(next.getSub, sublvl+1) + dict("end");
            }

            //add next
            next = next.child;
            ret +=next.getCommand() + "\n";

        }
}

ArgumentStruct* CodeGenerator::getCommand()
{
    //todo get arg struct von diesem block
}

//einrückungen etc.
QString subident(int sub)
{
    QString str ="";
    for (int i = 0; i<sub;i++)
    {
        str += dict(tab);
    }
    return str;
}

//translate ccommand in reqired language
//uses special commands :start, end, tab
QString dict(ArgumentStruct* argument)
{

    if (argument->arg1 == "")
    {
        return map["argument->name"];
    }
    else
    {
        //default args

        //special args
    }
    return "translation\n";
}

