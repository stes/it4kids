#include "paramdirection.h"

ParamDirection::ParamDirection(QWidget *parent) : QComboBox(parent)
{
    addItem("right");
    addItem("left");
    addItem("up");
    addItem("down");
    #pragma message("Fix GetValue")
}

QString ParamDirection::getValue()
{
    return QString("ParamDirection");
}

ParamDirection::~ParamDirection()
{

}

