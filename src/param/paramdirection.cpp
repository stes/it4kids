#include "paramdirection.h"

ParamDirection::ParamDirection(QWidget *parent) : QComboBox(parent)
{
    addItem("right");
    addItem("left");
    addItem("up");
    addItem("down");
}

QString ParamDirection::getValue()
{
    return '"' + currentText().toHtmlEscaped() + '"';
}

ParamDirection::~ParamDirection()
{

}

