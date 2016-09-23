#include "hatde.h"

#include "sprite.h"

HatDE::HatDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
     DraggableElement(identifier, text, color, sprite, parent),
     _lowerDock(ScriptDock::Lower, sprite, this)
{
    _paramLayout->setContentsMargins(8,6+10,8,6+4);
    setLayout(_paramLayout);
}

DraggableElement* HatDE::getCurrentElement(Sprite *sprite, QWidget* parent)
{
    return copyParams(new HatDE(_identifier, _text, _color, sprite, parent));
}

void HatDE::rearrangeLowerElems()
{
    DraggableElement* nextElem = _nextElem;

    if(nextElem)
    {
        nextElem->raise();
        nextElem->move(_lowerDock.getDockingPos());
        nextElem->rearrangeLowerElems();
    }
}

void HatDE::resizeEvent(QResizeEvent* event)
{
    DraggableElement::resizeEvent(event);
    QSize size = event->size();

    _path = QPainterPath();
    _path.moveTo(30, 10);
    _path.arcTo(0, 0, 60, 20, 180, -180);
    _path.moveTo(0, 10);
    _path.lineTo(size.width(), 10);
    _path.lineTo(size.width(), size.height()-4);
    _path.lineTo(25, size.height()-4);
    _path.lineTo(22, size.height());
    _path.lineTo(11, size.height());
    _path.lineTo(7, size.height()-4);
    _path.lineTo(0, size.height()-4);
}

void HatDE::removeChildDragElems()
{
    if(_lowerDock.getDockedElem()) _lowerDock.getDockedElem()->removeChildDragElems();
    _sprite->removeElement(this);
    delete this;
}

ScriptDock *HatDE::getDock(ScriptDock::Type type)
{
    if(type == ScriptDock::Lower)
        return &_lowerDock;
    return 0;
}

void HatDE::updateDocks()
{
    _lowerDock.setDock(mapToGlobal(QPoint(0,size().height()-4)), size().width());
}
