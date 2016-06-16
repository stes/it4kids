#include <QLineEdit>

#include "paramstring.h"

ParamString::ParamString(QWidget *parent) : _lineEdit(new QLineEdit(parent))
{
    _lineEdit->setFixedSize(50, 15);
    _lineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    _lineEdit->setFont(QFont("Courier", 7));
    // TODO: Fix GetValue
}

QString ParamString::getString() const
{
    return _lineEdit->text();
}

bool ParamString::setValue(const QString &value)
{
    _lineEdit->setText(value);
    return true;
}

QWidget* ParamString::getWidget()
{
    return _lineEdit;
}

ParamString::~ParamString()
{
}
