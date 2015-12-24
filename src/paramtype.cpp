#include "paramtype.h"

ParamType::ParamType(QWidget *parent) : QComboBox(parent)
{
    addItem("number");
    addItem("text");
    addItem("Boolean");
    addItem("list");
    addItem("command");
    addItem("reporter");
    addItem("predicate");
    #pragma message("Fix GetValue")
}

QString ParamType::getValue()
{
    return QString("ParamType");
}

ParamType::~ParamType()
{

}

