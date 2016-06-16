#include <QComboBox>

#include "paramtouch.h"

#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

ParamTouch::ParamTouch(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("mouse");
    _comboBox->addItem("edge");
    _comboBox->addItem("pen trails");
    const SpriteVector* sV = sMainWindow->getSpriteVector();
    for (SpriteVector::const_iterator it = sV->begin(); it != sV->end(); it++)
    {
        _comboBox->addItem((*it)->getName());
    }
}

ParamTouch::~ParamTouch()
{
}
