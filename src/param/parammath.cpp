#include <QComboBox>

#include "parammath.h"

ParamMath::ParamMath(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("sin");
    _comboBox->addItem("cos");
    _comboBox->addItem("tan");
    _comboBox->addItem("cotan");
    _comboBox->addItem("e^");
}

ParamMath::~ParamMath()
{
}
