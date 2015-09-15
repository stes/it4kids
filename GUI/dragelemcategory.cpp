#include "dragelemcategory.h"
#include <QDebug>
DragElemCategory::DragElemCategory(QString name, QColor color, QWidget *parent) : QWidget(parent),
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
    DragableElement* element = new DragableElement("gehe *QPixmap(:/Assets/greenFlagOn.png)* Schritte", _color, _elemListWidget);
    DragableElement* element2 = new DragableElement("drehe dich *QPixmap(:/Assets/clockwise.png)* um *QTextEdit()* Grad", _color, _elemListWidget);
    _elemList.push_back(element);
    _elemList.push_back(element2);
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
