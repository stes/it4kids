#include "commandde.h"

#include "sprite.h"

CommandDE::CommandDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite, QWidget* parent) :
    DraggableElement(identifier, text, color, sprite, parent),
    _upperDock(ScriptDock::Upper, sprite, this),
    _lowerDock(ScriptDock::Lower, sprite, this)
{
    _paramLayout->setContentsMargins(8,6,8,6+4);
    setLayout(_paramLayout);
}

DraggableElement* CommandDE::getCurrentElement(Sprite *sprite, QWidget *parent)
{
    return copyParams(new CommandDE(_identifier, _text, _color, sprite, parent));
}

void CommandDE::rearrangeUpperElems()
{
    DraggableElement* prevElem = _prevElem;

    if(prevElem)
    {
        prevElem->raise();
        prevElem->move(_upperDock.getDockingPos() - QPoint(0, prevElem->size().height()-4));
        prevElem->rearrangeUpperElems();
    }
}

void CommandDE::rearrangeLowerElems()
{
    DraggableElement* nextElem = _nextElem;

    if(nextElem)
    {
        nextElem->raise();
        nextElem->move(_lowerDock.getDockingPos());
        nextElem->rearrangeLowerElems();
    }
}

void CommandDE::resizeEvent(QResizeEvent* event)
{
    DraggableElement::resizeEvent(event);
    QSize size = event->size();

    _path = QPainterPath();
    _path.lineTo(7, 0);
    _path.lineTo(11, 4);
    _path.lineTo(21, 4);
    _path.lineTo(25, 0);
    _path.lineTo(size.width(), 0);
    _path.lineTo(size.width(), size.height()-4);
    _path.lineTo(25, size.height()-4);
    _path.lineTo(22, size.height());
    _path.lineTo(11, size.height());
    _path.lineTo(7, size.height()-4);
    _path.lineTo(0, size.height()-4);
    _path.closeSubpath();
}

void CommandDE::removeChildDragElems()
{
    if(_lowerDock.getDockedElem()) _lowerDock.getDockedElem()->removeChildDragElems();
    _sprite->removeElement(this);
    delete this;
}

ScriptDock *CommandDE::getDock(ScriptDock::Type type)
{
    if(type == ScriptDock::Upper)
        return &_upperDock;
    if(type == ScriptDock::Lower)
        return &_lowerDock;
    return 0;
}

void CommandDE::updateDocks()
{
    _upperDock.setDock(mapToGlobal(QPoint(0,0)), size().width());
    _lowerDock.setDock(mapToGlobal(QPoint(0,size().height()-4)), size().width());
}

CommandDE::~CommandDE()
{

}
