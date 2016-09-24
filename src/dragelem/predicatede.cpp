#include "predicatede.h"

#include "sprite.h"

PredicateDE::PredicateDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
    DraggableElement(identifier, text, color, sprite, parent)
{
    _paramLayout->setContentsMargins(8,3,8,3);
    setLayout(_paramLayout);
}

void PredicateDE::resizeEvent(QResizeEvent* event)
{
    DraggableElement::resizeEvent(event);
    QSize size = event->size();

    _path = QPainterPath();
    _path.moveTo(0, size.height()/2);
    _path.lineTo(10, 0);
    _path.lineTo(size.width()-10, 0);
    _path.lineTo(size.width(), size.height()/2);
    _path.lineTo(size.width()-10, size.height());
    _path.lineTo(10, size.height());
    _path.lineTo(0, size.height()/2);
}

void PredicateDE::removeChildDragElems()
{
    _sprite->removeElement(this);
    delete this;
}

DraggableElement* PredicateDE::getCurrentElement(Sprite *sprite, QWidget *parent)
{
    return copyParams(new PredicateDE(_identifier, _text, _color, sprite, parent));
}

PredicateDE::~PredicateDE()
{

}
