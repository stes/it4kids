#include <QDoubleValidator>

#include "paramnumber.h"

NumberWidget::NumberWidget(Sprite *sprite, DraggableElement *elemParent, QWidget* parent)
    : QLineEdit(parent), _dock(sprite, elemParent, this, DraggableElement::Reporter)
{
}

NumberWidget::~NumberWidget()
{
}

void NumberWidget::paintEvent(QPaintEvent* event)
{
    QLineEdit::paintEvent(event);

    // TODO: move somewhere else
    _dock.setRect(QRect(mapToGlobal(QPoint(0, 0)), size()));
}

ParamNumber::ParamNumber(Sprite *sprite, DraggableElement *elemParent, QWidget* parent)
    : _lineEdit(new NumberWidget(sprite, elemParent, parent))
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
}

ParamNumber::~ParamNumber()
{
    if(_lineEdit->getDock()->getDockedElem()) _lineEdit->getDock()->getDockedElem()->removeChildDragElems();
}
