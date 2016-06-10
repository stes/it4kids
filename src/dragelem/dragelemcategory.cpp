#include "dragelemcategory.h"

DragElemCategory::DragElemCategory(DragElemList *elemListWidget, const QString& name, const QColor& color, QWidget *parent) :
    QWidget(parent), _elemListWidget(elemListWidget),
    _label(name, this), _color(color)
{

}

void DragElemCategory::toggleActive()
{
    if(_elemListWidget)
    {
        _elemListWidget->changeActiveList(&_elemList);
    }
}

void DragElemCategory::setElemListWidget(DragElemList *elemListWidget)
{
    _elemListWidget = elemListWidget;
}

void DragElemCategory::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(_color));
    painter.drawRect(QRect(0, 0, 7, 15));
    _label.move(10, 0);
}

void DragElemCategory::mousePressEvent(QMouseEvent*)
{
    toggleActive();
}

void DragElemCategory::showEvent(QShowEvent *)
{
    if(_label.text() == QLatin1String("motion"))
    {
        toggleActive();
    }
}

DragElemCategory::~DragElemCategory()
{
}
