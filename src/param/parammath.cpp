#include <QComboBox>

#include "parammath.h"

ParamMath::ParamMath(QWidget *parent) : _comboBox(new QComboBox(parent))
{
    _comboBox->addItem("sin");
    _comboBox->addItem("cos");
    _comboBox->addItem("tan");
    _comboBox->addItem("cotan");
    _comboBox->addItem("e^");
}

bool ParamMath::setValue(const QString &val)
{
    _comboBox->setCurrentText(val);
    return true;
}

QString ParamMath::getValue() const
{
    return _comboBox->currentText();
}

QWidget* ParamMath::getWidget()
{
    return _comboBox;
};

ParamMath::~ParamMath()
{
}
