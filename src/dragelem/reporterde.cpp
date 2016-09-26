#include "reporterde.h"

#include "sprite.h"

ReporterDE::ReporterDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
     DraggableElement(identifier, text, color, sprite, parent)
{
    _paramLayout->setContentsMargins(8, 3, 8, 3);
    setLayout(_paramLayout);
}

DraggableElement* ReporterDE::getCurrentElement(Sprite *sprite, QWidget* parent)
{
    return copyParams(new ReporterDE(_identifier, _text, _color, sprite, parent));
}

void ReporterDE::resizeEvent(QResizeEvent* event)
{
    DraggableElement::resizeEvent(event);
    QSize size = event->size();

    _path = QPainterPath();
    _path.moveTo(size.height()/2, 0);
    _path.arcTo(0, 0, size.height(), size.height(), 90, 180);
    _path.lineTo(size.width() - size.height()/2, size.height());
    _path.arcTo(size.width() - size.height(), 0, size.height(), size.height(), 270, 180);
    _path.closeSubpath();
}

void ReporterDE::removeChildDragElems()
{
    _sprite->removeElement(this);
    delete this;
}

ReporterDE::~ReporterDE()
{

}

