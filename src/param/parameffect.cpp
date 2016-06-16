#include <QComboBox>

#include "parameffect.h"

ParamEffect::ParamEffect(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("ghost");
    _comboBox->addItem("brightness");
    _comboBox->addItem("negative");
    _comboBox->addItem("comic");
    _comboBox->addItem("duplicate");
    _comboBox->addItem("confetti");
}

ParamEffect::~ParamEffect()
{

}
