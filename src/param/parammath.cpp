#include <QComboBox>

#include "parammath.h"

ParamMath::ParamMath(QWidget *parent) : ParamComboBox(parent)
{
    // TODO: move to blocks file
    _comboBox->addItem("abs");
    _comboBox->addItem("floor");
    _comboBox->addItem("ceil");
    _comboBox->addItem("sqrt");
    _comboBox->addItem("sin");
    _comboBox->addItem("cos");
    _comboBox->addItem("tan");
    _comboBox->addItem("asin");
    _comboBox->addItem("acos");
    _comboBox->addItem("atan");
    _comboBox->addItem("ln");
    _comboBox->addItem("e^");
}

ParamMath::~ParamMath()
{
}
