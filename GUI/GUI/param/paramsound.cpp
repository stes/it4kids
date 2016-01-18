#include "paramsound.h"

ParamSound::ParamSound(QWidget *parent) : QComboBox(parent)
{
    addItem("sound1");
    //#warning "Add Sound list to ParamSound"
}

QString ParamSound::getValue()
{
    return QString("ParamSound");
}

ParamSound::~ParamSound()
{

}


