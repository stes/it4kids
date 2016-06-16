#include <QComboBox>

#include "paramcostume.h"

#include "costume/costume.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

ParamCostume::ParamCostume(QWidget *parent, Sprite *sprite) : ParamComboBox(parent), _sprite(sprite)
{
    connect(sMainWindow, SIGNAL(newCostume()), this, SLOT(updateCostumeList()));
    updateCostumeList();
}

ParamCostume::~ParamCostume()
{
}

void ParamCostume::updateCostumeList()
{
    _comboBox->clear();
    Sprite *sprite = _sprite ? _sprite : sMainWindow->getCurrentSprite();
    const CostumeVector *costumeVec = sprite->getCostumeVector();
    for(CostumeVector::const_iterator it = costumeVec->begin(); it != costumeVec->end(); it++)
    {
        _comboBox->addItem((*it)->getName());
    }
}


