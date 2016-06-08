#include <QDoubleValidator>

#include "paramnumber.h"

ParamNumber::ParamNumber(QWidget* parent) : QLineEdit(parent)
{
    //setInputMask("9999");
    setValidator(new QDoubleValidator());
    setFixedSize(20, 15);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setFont(QFont("Courier", 7));
}

double ParamNumber::getNumber() const
{
    return text().toDouble();
}

bool ParamNumber::setValue(const QString& value)
{
    setText(value);
    return 1;
}

ParamNumber::~ParamNumber()
{

}
