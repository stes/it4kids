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
}

QString ParamType::getString() const
{
    return currentText();
}

ParamType::~ParamType()
{

}

