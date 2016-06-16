#include <QComboBox>

#include "paramclone.h"

#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* sMainWindow;

ParamClone::ParamClone(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("myself");
    const SpriteVector* sV = sMainWindow->getSpriteVector();
    for(SpriteVector::const_iterator it = sV->begin(); it != sV->end(); it++)
    {
        _comboBox->addItem((*it)->getName());
    }
}

ParamClone::~ParamClone()
{
}
