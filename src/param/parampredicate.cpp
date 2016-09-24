#include <QPainter>

#include "parampredicate.h"

PredicateWidget::PredicateWidget(Sprite *sprite, DraggableElement *elemParent, QColor color, QWidget *parent)
    : QWidget(parent), _dock(sprite, elemParent, this, DraggableElement::Predicate)
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

    // TODO: move somewhere else
    _dock.setRect(QRect(mapToGlobal(QPoint(0, 0)), QSize(24, 12)));
}

ParamPredicate::ParamPredicate(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent)
    : _dockWidget(new PredicateWidget(sprite, elemParent, color, parent))
{
}

ParamPredicate::~ParamPredicate()
{
    if(_dockWidget->getDock()->getDockedElem()) _dockWidget->getDock()->getDockedElem()->removeChildDragElems();
}

QString ParamPredicate::getValue() const
{
    return "None";
}
