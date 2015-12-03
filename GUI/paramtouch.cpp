#include "paramtouch.h"

ParamTouch::ParamTouch(QWidget *parent) : QComboBox(parent)
{
    addItem("mouse");
    //#warning "Add Touch list to ParamTouch"
}

QString ParamTouch::getValue()
{
    return QString("ParamTouch");
}

ParamTouch::~ParamTouch()
{

}


