#include "paramcostume.h"

#include "mainwindow.h"
#include "costume.h"
#include "sprite.h"

extern MainWindow* _sMainWindow;

ParamCostume::ParamCostume(QWidget *parent) : QComboBox(parent)
{
    CostumeVector* cV = _sMainWindow->getCurrentSprite()->getCostumeVector();
    for(uint i = 0; i < cV->size(); i++)
    {
        addItem(cV->at(i)->getName());
    }
}

QString ParamCostume::getValue()
{
    return currentText();
}

ParamCostume::~ParamCostume()
{

}


