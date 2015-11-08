#include "parammath.h"

ParamMath::ParamMath(QWidget *parent) : QComboBox(parent)
{
    addItem("sin");
    addItem("cos");
    addItem("tan");
    addItem("cotan");
    addItem("e^");
    #warning "Add Math list to ParamMath"
}

QString ParamMath::getValue()
{
    return QString("ParamMath");
}

ParamMath::~ParamMath()
{

}


