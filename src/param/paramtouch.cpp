#include "paramtouch.h"

#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* sMainWindow;

ParamTouch::ParamTouch(QWidget *parent) : QComboBox(parent)
{
    addItem("mouse");
    addItem("edge");
    addItem("pen trails");
    SpriteVector* sV = sMainWindow->getSpriteVector();
    for(uint i = 0; i < sV->size(); i++)
    {
        addItem(sV->at(i)->getName());
    }
}

QString ParamTouch::getString() const
{
    return currentText();
}

ParamTouch::~ParamTouch()
{

}


