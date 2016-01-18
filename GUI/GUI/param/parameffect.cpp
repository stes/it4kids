#include "parameffect.h"

ParamEffect::ParamEffect(QWidget *parent) : QComboBox(parent)
{
    addItem("ghost");
    addItem("brightness");
    addItem("negative");
    addItem("comic");
    addItem("duplicate");
    addItem("confetti");
    #pragma message("Fix GetValue")
}

QString ParamEffect::getValue()
{
    return QString("ParamEffect");
}

ParamEffect::~ParamEffect()
{

}

