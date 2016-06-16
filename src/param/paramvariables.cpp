#include <QComboBox>

#include "paramvariables.h"

ParamVariables::ParamVariables(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("a");
    //#warning "Add Variables list to ParamVariables"
}

ParamVariables::~ParamVariables()
{
}
