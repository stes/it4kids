#include <QPainter>

#include "parampredicate.h"

PredicateWidget::PredicateWidget(QColor color, QWidget *parent) : QWidget(parent), _color(color)
{
    _path.moveTo(1, 7);
    _path.lineTo(7, 1);
    _path.lineTo(19, 1);
    _path.lineTo(25, 7);
    _path.lineTo(19, 13);
    _path.lineTo(7, 13);
    _path.lineTo(1, 7);
    setFixedSize(26, 14);
}

PredicateWidget::~PredicateWidget()
{
}

void PredicateWidget::paintEvent(QPaintEvent*)
{
    QPen pen(_color.darker(120), 2, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    QBrush brush(_color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPath(_path);
}

ParamPredicate::ParamPredicate(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent)
{
    _predicateWidget = new PredicateWidget(color, parent);
    _dockWidget = new DockWrapperWidget(sprite, elemParent, _predicateWidget, DraggableElement::Predicate);
}

ParamPredicate::~ParamPredicate()
{
}
