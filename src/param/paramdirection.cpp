#include <QComboBox>

#include "paramdirection.h"

ParamDirection::ParamDirection(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("right");
    _comboBox->addItem("left");
    _comboBox->addItem("up");
    _comboBox->addItem("down");
}

ParamDirection::~ParamDirection()
{

}

