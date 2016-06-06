#include "paramclone.h"

#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* _sMainWindow;

ParamClone::ParamClone(QWidget *parent) : QComboBox(parent)
{
    addItem("myself");
    SpriteVector* sV = _sMainWindow->getSpriteVector();
    for(uint i = 0; i < sV->size(); i++)
    {
        addItem(sV->at(i)->getName());
    }
}

QString ParamClone::getValue()
{
    return addQuotes(currentText());
}

ParamClone::~ParamClone()
{

}
