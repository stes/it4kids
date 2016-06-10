#include "reporterde.h"

ReporterDE::ReporterDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
     DraggableElement(identifier, text, color, DraggableElement::Reporter, sprite, parent)
{
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(4, 4, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
}

DraggableElement* ReporterDE::getCurrentElement(Sprite *sprite, QWidget* parent)
{
    return copyParams(new ReporterDE(_identifier, _text, _color, sprite, parent));
}

void ReporterDE::resize()
{
    bool visible = isVisible();
    if(!visible) show();

    getLayoutSize();
    _path = QPainterPath();
    _path.moveTo(5, (_height+5)/2);
    _path.arcTo(0, 0, 10, _height+5, 90, 180);
    _path.moveTo(_width+5-5, (_height+5)/2);
    _path.arcTo(_width+5-10, 0, 10, _height+5, 270, 180);
    _path.moveTo(5, 0);
    _path.lineTo(_width+5-5, 0);
    _path.lineTo(_width+5-5, _height+5);
    _path.lineTo(5, _height+5);
    _path.lineTo(5, 0);
    setFixedSize(_width+10, _height+5);

    if(!visible) hide();
}

void ReporterDE::removeChildDragElems()
{
    _sprite->removeElement(this);
    delete this;
}

void ReporterDE::hitTest()
{

}

ReporterDE::~ReporterDE()
{

}

