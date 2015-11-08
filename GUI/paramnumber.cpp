#include "paramnumber.h"

ParamNumber::ParamNumber(QWidget* parent) : QLineEdit(parent)
{
    setInputMask("9999");
    setFixedSize(20, 15);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setFont(QFont("Courier", 7));
}

QString ParamNumber::getValue()
{
    return QString("ParamNumber");
}

ParamNumber::~ParamNumber()
{

}
