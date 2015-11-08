#include "paramstring.h"

ParamString::ParamString(QWidget *parent) : QLineEdit(parent)
{
    setFixedSize(50, 15);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setFont(QFont("Courier", 7));
}

QString ParamString::getValue()
{
    return QString("ParamString");
}

ParamString::~ParamString()
{

}

