#include <QPainter>

#include "parampredicate.h"

PredicateWidget::PredicateWidget(QColor color, QWidget *parent) : QWidget(parent)
{
    _color = color.darker(130);

    _path.moveTo(0, 6);
    _path.lineTo(6, 0);
    _path.lineTo(18, 0);
    _path.lineTo(24,6);
    _path.lineTo(18, 12);
    _path.lineTo(6, 12);
    _path.lineTo(0, 6);
    setFixedSize(24, 12);
}

PredicateWidget::~PredicateWidget()
{
}

void PredicateWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // style(), width(), brush(), capStyle() and joinStyle().
    QPen pen(QColor(_color), 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(pen);

    // Brush
    QBrush brush;
    brush.setColor(QColor(_color));
    brush.setStyle(Qt::SolidPattern);

    // Draw polygon
    painter.fillPath(_path, brush);
    painter.setBackgroundMode(Qt::TransparentMode);
}

ParamPredicate::ParamPredicate(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent)
{
    _predicateWidget = new PredicateWidget(color, parent);
    _dockWidget = new DockWrapperWidget(sprite, elemParent, _predicateWidget, DraggableElement::Predicate);
}

ParamPredicate::~ParamPredicate()
{
}
