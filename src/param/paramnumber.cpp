#include <QDoubleValidator>

#include "paramnumber.h"

NumberWidget::~NumberWidget()
{
}

ParamNumber::ParamNumber(QWidget* parent) : _lineEdit(new NumberWidget(parent))
{
    //setInputMask("9999");
    _lineEdit->setValidator(new QDoubleValidator());
    _lineEdit->setFixedSize(20, 15);
    _lineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    _lineEdit->setFont(QFont("Courier", 7));
}

double ParamNumber::getNumber() const
{
    return _lineEdit->text().toDouble();
}

bool ParamNumber::setValue(const QString& value)
{
    _lineEdit->setText(value);
    return 1;
}

QWidget* ParamNumber::getWidget()
{
    return _lineEdit;
};

ParamNumber::~ParamNumber()
{
}
