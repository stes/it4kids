#include "paramkey.h"

ParamKey::ParamKey(QWidget *parent) : QComboBox(parent)
{
    addItem("a");
    addItem("b");
    addItem("c");
    addItem("d");
    addItem("e");
    //#warning "Add Key list to ParamKey"
}

QString ParamKey::getValue()
{
    return QString("ParamKey");
}

ParamKey::~ParamKey()
{

}
