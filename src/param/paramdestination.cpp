#include <QComboBox>

#include "paramdestination.h"

#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

ParamDestination::ParamDestination(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("mouse");
    const SpriteVector* sV = sMainWindow->getSpriteVector();
    for (SpriteVector::const_iterator it = sV->begin(); it != sV->end(); it++)
    {
        _comboBox->addItem((*it)->getName());
    }
}

ParamDestination::~ParamDestination()
{
}
