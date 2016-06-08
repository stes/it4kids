#include "paramkey.h"

ParamKey::ParamKey(QWidget *parent) : QComboBox(parent)
{
    addItem("a");
    addItem("b");
    addItem("c");
    addItem("d");
    addItem("e");
    addItem("f");
    addItem("g");
    addItem("h");
    addItem("i");
    addItem("k");
    addItem("l");
    addItem("m");
    addItem("n");
    addItem("o");
    addItem("p");
    addItem("q");
    addItem("r");
    addItem("s");
    addItem("t");
    addItem("u");
    addItem("v");
    addItem("w");
    addItem("x");
    addItem("y");
    addItem("z");
    addItem("1");
    addItem("2");
    addItem("3");
    addItem("4");
    addItem("5");
    addItem("6");
    addItem("7");
    addItem("8");
    addItem("9");
    addItem("0");
    addItem("Left Arrow");
    addItem("Right Arrow");
    addItem("Up Arrow");
    addItem("Down Arrow");
}

QString ParamKey::getString() const
{
    return currentText();
}

ParamKey::~ParamKey()
{

}
