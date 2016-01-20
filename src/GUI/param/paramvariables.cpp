#include "paramvariables.h"

ParamVariables::ParamVariables(QWidget *parent) : QComboBox(parent)
{
    addItem("a");
    //#warning "Add Variables list to ParamVariables"
}

QString ParamVariables::getValue()
{
    return QString("ParamVariables");
}

ParamVariables::~ParamVariables()
{

}
