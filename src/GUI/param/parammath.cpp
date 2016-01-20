#include "parammath.h"

ParamMath::ParamMath(QWidget *parent) : QComboBox(parent)
{
    addItem("sin");
    addItem("cos");
    addItem("tan");
    addItem("cotan");
    addItem("e^");
}

QString ParamMath::getValue()
{
    return currentText();
}

ParamMath::~ParamMath()
{

}


