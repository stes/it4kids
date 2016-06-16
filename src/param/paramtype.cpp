#include <QComboBox>

#include "paramtype.h"

ParamType::ParamType(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("number");
    _comboBox->addItem("text");
    _comboBox->addItem("Boolean");
    _comboBox->addItem("list");
    _comboBox->addItem("command");
    _comboBox->addItem("reporter");
    _comboBox->addItem("predicate");
}

ParamType::~ParamType()
{
}
