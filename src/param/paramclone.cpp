#include "paramclone.h"

#include "mainwindow.h"
#include "sprite.h"
#include "spriteselect.h"

extern MainWindow* sMainWindow;

ParamClone::ParamClone(QWidget *parent) : QComboBox(parent)
{
    addItem("myself");
    const SpriteVector* sV = sMainWindow->getSpriteVector();
    for(SpriteVector::const_iterator it = sV->begin(); it != sV->end(); it++)
    {
        addItem((*it)->getName());
    }
}

bool ParamClone::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamClone::getString() const
{
    return currentText();
}

ParamClone::~ParamClone()
{

}
