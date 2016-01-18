#include "paramclone.h"

ParamClone::ParamClone(QWidget *parent) : QComboBox(parent)
{
    addItem("myself");
    #pragma message("Add sprite list")
}

QString ParamClone::getValue()
{
    return QString("ParamClone");
}

ParamClone::~ParamClone()
{

}
