#include "paramcostume.h"

ParamCostume::ParamCostume(QWidget *parent) : QComboBox(parent)
{
    addItem("Turtle");
    //#warning "Add Costume list to ParamCostume"
}

QString ParamCostume::getValue()
{
    return QString("ParamCostume");
}

ParamCostume::~ParamCostume()
{

}


