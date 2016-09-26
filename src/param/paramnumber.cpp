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
    _lineEdit->setFixedSize(30, 20);
    _lineEdit->setAlignment(Qt::AlignCenter);
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
