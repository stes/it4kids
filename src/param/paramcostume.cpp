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
    CostumeVector* cV = sprite->getCostumeVector();
    for(uint i = 0; i < cV->size(); i++)
    {
        addItem(cV->at(i)->getName());
    }
}


