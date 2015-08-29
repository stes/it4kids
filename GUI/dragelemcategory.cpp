#include "dragelemcategory.h"
#include <QDebug>
DragElemCategory::DragElemCategory(QString name, QColor color, QWidget *parent) : QWidget(parent),
    _label(name, this), _color(color)
{
    DragableElement* element = new DragableElement("Fuck this", _color, this);
    _elemList.push_back(element);
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

void DragElemCategory::mousePressEvent(QMouseEvent *event)
{
    toggleActive();
}
