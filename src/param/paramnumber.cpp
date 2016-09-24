#include <QDoubleValidator>

#include "paramnumber.h"

NumberWidget::NumberWidget(QWidget* parent) : QLineEdit(parent)
{
}

NumberWidget::~NumberWidget()
{
}

ParamNumber::ParamNumber(Sprite *sprite, DraggableElement *elemParent, QWidget* parent)
{
    //setInputMask("9999");
    _lineEdit = new NumberWidget(parent);
    _lineEdit->setValidator(new QDoubleValidator());
    _lineEdit->setFixedSize(20, 15);
    _lineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    _lineEdit->setFont(QFont("Courier", 7));
    _dockWidget = new DockWrapperWidget(sprite, elemParent, _lineEdit, DraggableElement::Reporter);

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

ParamNumber::~ParamNumber()
{
}
