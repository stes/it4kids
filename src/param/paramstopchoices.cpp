#include <QComboBox>

#include "paramstopchoices.h"

ParamStopChoices::ParamStopChoices(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("all");
    _comboBox->addItem("this Script");
    _comboBox->addItem("this Block");
    _comboBox->addItem("all but this Script");
    _comboBox->addItem("other Scripts in Sprite");
}

ParamStopChoices::~ParamStopChoices()
{
}
