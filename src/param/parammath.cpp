#include "parammath.h"

ParamMath::ParamMath(QWidget *parent) : QComboBox(parent)
{
    addItem("sin");
    addItem("cos");
    addItem("tan");
    addItem("cotan");
    addItem("e^");
}

bool ParamMath::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamMath::getValue() const
{
    return currentText();
}

ParamMath::~ParamMath()
{

}


