#include "dragelemcategory.h"
#include <QDebug>
DragElemCategory::DragElemCategory(const QString& name, const QColor& color, QWidget *parent) : QWidget(parent),
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

void DragElemCategory::setScriptAreaWidget(ScriptArea *scriptAreaWidget)
{
    _scriptAreaWidget = scriptAreaWidget;
    for(ElementList::iterator element = _elemList.begin(); element != _elemList.end(); element++)
    {
        (*element)->setScriptAreaWidget(scriptAreaWidget);
    }
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

DragElemCategory::~DragElemCategory()
{

}
