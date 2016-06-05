#include "paramcostume.h"

#include "costume/costume.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* _sMainWindow;

ParamCostume::ParamCostume(QWidget *parent) : QComboBox(parent)
{
    connect(_sMainWindow, SIGNAL(newCostume()), this, SLOT(updateCostumeList()));
    updateCostumeList();
}

QString ParamCostume::getValue()
{
    return currentText();
}

ParamCostume::~ParamCostume()
{

}

void ParamCostume::updateCostumeList()
{
    CostumeVector* cV = _sMainWindow->getCurrentSprite()->getCostumeVector();
    for(uint i = 0; i < cV->size(); i++)
    {
        addItem(cV->at(i)->getName());
    }
}


