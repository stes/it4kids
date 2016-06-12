#include "paramdirection.h"

ParamDirection::ParamDirection(QWidget *parent) : QComboBox(parent)
{
    addItem("right");
    addItem("left");
    addItem("up");
    addItem("down");
}

bool ParamDirection::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamDirection::getString() const
{
    return currentText();
}

ParamDirection::~ParamDirection()
{

}

