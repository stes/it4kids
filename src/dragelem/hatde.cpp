#include "hatde.h"

HatDE::HatDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
     DraggableElement(identifier, text, color, DraggableElement::Hat, sprite, parent),
     _lowerDock(ScriptDock::Lower, sprite, this)
{
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(4, 4, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
}

DraggableElement* HatDE::getCurrentElement(Sprite *sprite, QWidget* parent)
{
    return copyParams(new HatDE(_identifier, _text, _color, sprite, parent));
}

void HatDE::rearrangeLowerElems()
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

void HatDE::resize()
{
    bool visible = isVisible();
    if(!visible) show();

    getLayoutSize();
    _path = QPainterPath();
    _path.moveTo(30, 10);
    _path.arcTo(0, 0, 60, 20, 180, -180);
    _path.moveTo(0, 10);
    _path.lineTo(_width+5, 10);
    _path.lineTo(_width+5, 16+_height);
    _path.lineTo(25, 16+_height);
    _path.lineTo(22, 20+_height);
    _path.lineTo(11, 20+_height);
    _path.lineTo(7, 16+_height);
    _path.lineTo(0, 16+_height);
    setFixedSize(_width+5, _height+20);

    if(!visible) hide();
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

void HatDE::moveEvent(QMoveEvent *)
{
    _lowerDock.setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height+10), QSize(_width, _height)));
}
