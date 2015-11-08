#include "predicatede.h"
#include "paramdock.h"

PredicateDE::PredicateDE(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget, QWidget* parent) :
    DragableElement(text, color, type, scriptAreaWidget, parent)
{
    parseText(text, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(10, 0, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
}

void PredicateDE::resize()
{
    show();

    _width = _layout.geometry().normalized().width();
    _height = _layout.geometry().normalized().height();
    _path = QPainterPath();
    _path.moveTo(0, (_height+4)/2);
    _path.lineTo(10, 0);
    _path.lineTo(_width+5, 0);
    _path.lineTo(_width+15, (_height+4)/2);
    _path.lineTo(_width+5, _height+4);
    _path.lineTo(10, _height+4);
    _path.lineTo(0, (_height+4)/2);
    _layout.setSizeConstraint(QLayout::SetNoConstraint);
    setFixedSize(_width+20, _height+4);

    hide();
}

void PredicateDE::mouseMoveEvent(QMouseEvent* event)
{
    DragableElement::mouseMoveEvent(event);
    HitTestVector* vector = _scriptAreaWidget->getHitTestVector();
    for(HitTestVector::iterator element = vector->begin(); element != vector->end(); element++)
    {
        QRect rectDock((*element)->mapToGlobal(pos()), QSize((*element)->width(), (*element)->height()));
        QRect rectDE(mapToGlobal(pos()), QSize(width(), height()));
        if(rectDock.intersects(rectDE))
        {
        }
    }
}

void PredicateDE::mouseReleaseEvent(QMouseEvent* event)
{
    DragableElement::mouseReleaseEvent(event);
    HitTestVector* vector = _scriptAreaWidget->getHitTestVector();
    for(HitTestVector::iterator element = vector->begin(); element != vector->end(); element++)
    {
        QRect rectDock((*element)->mapToGlobal(pos()), QSize((*element)->width(), (*element)->height()));
        QRect rectDE(mapToGlobal(pos()), QSize(width(), height()));
        if(rectDock.intersects(rectDE))
        {
            ((ParamDock*) (*element))->dock(this);
        }
    }
}

DragableElement* PredicateDE::getCurrentElement(QWidget *parent)
{
    return new PredicateDE(_text, _color, _type, _scriptAreaWidget, parent);
}
