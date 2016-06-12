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
    const SpriteVector* sV = sMainWindow->getSpriteVector();
    for (SpriteVector::const_iterator it = sV->begin(); it != sV->end(); it++)
    {
        addItem((*it)->getName());
    }
}

bool ParamTouch::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamTouch::getString() const
{
    return currentText();
}

ParamTouch::~ParamTouch()
{

}


