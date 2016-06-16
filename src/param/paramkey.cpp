#include <QComboBox>

#include "paramkey.h"

ParamKey::ParamKey(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("a");
    _comboBox->addItem("b");
    _comboBox->addItem("c");
    _comboBox->addItem("d");
    _comboBox->addItem("e");
    _comboBox->addItem("f");
    _comboBox->addItem("g");
    _comboBox->addItem("h");
    _comboBox->addItem("i");
    _comboBox->addItem("k");
    _comboBox->addItem("l");
    _comboBox->addItem("m");
    _comboBox->addItem("n");
    _comboBox->addItem("o");
    _comboBox->addItem("p");
    _comboBox->addItem("q");
    _comboBox->addItem("r");
    _comboBox->addItem("s");
    _comboBox->addItem("t");
    _comboBox->addItem("u");
    _comboBox->addItem("v");
    _comboBox->addItem("w");
    _comboBox->addItem("x");
    _comboBox->addItem("y");
    _comboBox->addItem("z");
    _comboBox->addItem("1");
    _comboBox->addItem("2");
    _comboBox->addItem("3");
    _comboBox->addItem("4");
    _comboBox->addItem("5");
    _comboBox->addItem("6");
    _comboBox->addItem("7");
    _comboBox->addItem("8");
    _comboBox->addItem("9");
    _comboBox->addItem("0");
    _comboBox->addItem("Left Arrow");
    _comboBox->addItem("Right Arrow");
    _comboBox->addItem("Up Arrow");
    _comboBox->addItem("Down Arrow");
}

ParamKey::~ParamKey()
{
}
