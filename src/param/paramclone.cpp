#include "paramclone.h"

#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* sMainWindow;

ParamClone::ParamClone(QWidget *parent) : QComboBox(parent)
{
    addItem("myself");
    SpriteVector* sV = sMainWindow->getSpriteVector();
    for(uint i = 0; i < sV->size(); i++)
    {
        addItem(sV->at(i)->getName());
    }
}

QString ParamClone::getString() const
{
    return currentText();
}

ParamClone::~ParamClone()
{

}
