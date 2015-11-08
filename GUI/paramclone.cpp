#include "paramclone.h"

ParamClone::ParamClone(QWidget *parent) : QComboBox(parent)
{
    addItem("myself");
    #warning "Add Sprite list to ParamClone"
}

QString ParamClone::getValue()
{
    return QString("ParamClone");
}

ParamClone::~ParamClone()
{

}
