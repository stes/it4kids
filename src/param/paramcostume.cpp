#include "paramcostume.h"

#include "costume/costume.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

ParamCostume::ParamCostume(QWidget *parent, Sprite *sprite) : QComboBox(parent), _sprite(sprite)
{
    connect(sMainWindow, SIGNAL(newCostume()), this, SLOT(updateCostumeList()));
    updateCostumeList();
}

bool ParamCostume::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamCostume::getString() const
{
    return currentText();
}

ParamCostume::~ParamCostume()
{
}

void ParamCostume::updateCostumeList()
{
    clear();
    Sprite *sprite = _sprite ? _sprite : sMainWindow->getCurrentSprite();
    const CostumeVector *costumeVec = sprite->getCostumeVector();
    for(CostumeVector::const_iterator it = costumeVec->begin(); it != costumeVec->end(); it++)
    {
        addItem((*it)->getName());
    }
}


