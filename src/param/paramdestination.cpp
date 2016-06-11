#include "paramdestination.h"

#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* sMainWindow;

ParamDestination::ParamDestination(QWidget *parent) : QComboBox(parent)
{
    addItem("mouse");
    const SpriteVector* sV = sMainWindow->getSpriteVector();
    for (SpriteVector::const_iterator it = sV->begin(); it != sV->end(); it++)
    {
        addItem((*it)->getName());
    }
}

QString ParamDestination::getString() const
{
    return currentText();
}

ParamDestination::~ParamDestination()
{

}

