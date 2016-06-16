#include "commandde.h"

#include "sprite.h"

CommandDE::CommandDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite, QWidget* parent) :
    DraggableElement(identifier, text, color, sprite, parent),
    _upperDock(ScriptDock::Upper, sprite, this),
    _lowerDock(ScriptDock::Lower, sprite, this)
{
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(4, 0, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
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
        prevElem->move(_upperDock.getRect()->topLeft() + prevElem->getUpperOffsett());
        prevElem->rearrangeUpperElems();
    }
}

void CommandDE::rearrangeLowerElems()
{
    if(!isVisible()) moveEvent(0); // force dock update

    DraggableElement* nextElem = _nextElem;

    if(nextElem)
    {
        nextElem->raise();
        nextElem->move(_lowerDock.getRect()->topLeft() + nextElem->getLowerOffsett());
        nextElem->rearrangeLowerElems();
    }
}

void CommandDE::resize()
{
    bool visible = isVisible();
    if(!visible) show();

    getLayoutSize();
    _path = QPainterPath();
    _path.lineTo(7, 0);
    _path.lineTo(11, 4);
    _path.lineTo(21, 4);
    _path.lineTo(25, 0);
    _path.lineTo(_width+5, 0);
    _path.lineTo(_width+5, _height+5);
    _path.lineTo(25, _height+5);
    _path.lineTo(22, _height+9);
    _path.lineTo(11, _height+9);
    _path.lineTo(7, _height+5);
    _path.lineTo(0, _height+5);

    setFixedSize(_width+5, _height+9);

    if(!visible) hide();
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

void CommandDE::moveEvent(QMoveEvent*)
{
    _upperDock.setRect(QRect(mapToGlobal(QPoint(0, 0)) - QPoint(0, 10), QSize(_width, _height)));
    _lowerDock.setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height), QSize(_width, _height)));
}

CommandDE::~CommandDE()
{

}
