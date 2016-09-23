#include "wrapperde.h"

#include "sprite.h"

WrapperDE::WrapperDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite, QWidget* parent) :
    DraggableElement(identifier, QString(text).remove(QStringLiteral("%c")), color, sprite, parent),
    _upperDock(ScriptDock::Upper, sprite, this),
    _lowerDock(ScriptDock::Lower, sprite, this),
    _innerDock(ScriptDock::Inner, sprite, this)
{
    _text = text;

    _innerSpace = new QSpacerItem(-1, -1);
    _paramLayout->setContentsMargins(8,6,8,6+4);

    _layout = new QVBoxLayout();
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
    _layout->addLayout(_paramLayout);
    _layout->addSpacerItem(_innerSpace);
    _layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(_layout);

    updateSize();
}

DraggableElement* WrapperDE::getCurrentElement(Sprite *sprite, QWidget *parent)
{
    return copyParams(new WrapperDE(_identifier, _text, _color, sprite, parent));
}

void WrapperDE::rearrangeUpperElems()
{
    rearrangeInnerElems();

    DraggableElement* prevElem = _prevElem;

    if(prevElem)
    {
        prevElem->raise();
        prevElem->move(_upperDock.getDockingPos() - QPoint(0, prevElem->size().height()-4));
        prevElem->rearrangeUpperElems();
    }
}

void WrapperDE::rearrangeLowerElems()
{
    rearrangeInnerElems();

    DraggableElement* nextElem = _nextElem;

    if(nextElem)
    {
        nextElem->raise();
        nextElem->move(_lowerDock.getDockingPos());
        nextElem->rearrangeLowerElems();
    }
}

void WrapperDE::rearrangeInnerElems()
{
    DraggableElement* innerElem = _innerDock.getDockedElem();

    if(innerElem)
    {
        innerElem->raise();
        innerElem->move(_innerDock.getDockingPos());
        innerElem->rearrangeLowerElems();
    }
}

void WrapperDE::updateSize()
{
    DraggableElement* innerElem = _innerDock.getDockedElem();

    int height = 0;
    while(innerElem)
    {
        height += innerElem->size().height()-4;
        innerElem = innerElem->getNextElem();
    }

    _innerSpace->changeSize(15, qMax(height, 8)+22+4, QSizePolicy::Fixed, QSizePolicy::Fixed);
    _layout->invalidate();
}

void WrapperDE::resizeEvent(QResizeEvent* event)
{
    DraggableElement::resizeEvent(event);
    QSize size = event->size();
    QSize paramSize = _paramLayout->sizeHint();

    _path = QPainterPath();
    _path.lineTo(7, 0);
    _path.lineTo(11, 4);
    _path.lineTo(21, 4);
    _path.lineTo(25, 0);
    _path.lineTo(paramSize.width(), 0);
    _path.lineTo(paramSize.width(), paramSize.height()-4);
    _path.lineTo(40, paramSize.height()-4);
    _path.lineTo(37, paramSize.height());
    _path.lineTo(26, paramSize.height());
    _path.lineTo(22, paramSize.height()-4);
    _path.lineTo(15, paramSize.height()-4);

    _path.lineTo(15, size.height()-4-22);
    _path.lineTo(paramSize.width(), size.height()-4-22);
    _path.lineTo(paramSize.width(), size.height()-4);

    _path.lineTo(25, size.height()-4);
    _path.lineTo(22, size.height());
    _path.lineTo(11, size.height());
    _path.lineTo(7, size.height()-4);
    _path.lineTo(0, size.height()-4);
}

void WrapperDE::removeChildDragElems()
{
    if(_innerDock.getDockedElem()) _innerDock.getDockedElem()->removeChildDragElems();
    if(_lowerDock.getDockedElem()) _lowerDock.getDockedElem()->removeChildDragElems();
    _sprite->removeElement(this);
    delete this;
}

ScriptDock *WrapperDE::getDock(ScriptDock::Type type)
{
    if(type == ScriptDock::Upper)
        return &_upperDock;
    if(type == ScriptDock::Lower)
        return &_lowerDock;
    if(type == ScriptDock::Inner)
        return &_innerDock;
    return 0;
}

void WrapperDE::updateDocks()
{
    _upperDock.setDock(mapToGlobal(QPoint(0,0)), size().width());
    _innerDock.setDock(mapToGlobal(QPoint(15,_paramLayout->sizeHint().height()-4)), size().width());
    _lowerDock.setDock(mapToGlobal(QPoint(0,size().height()-4)), size().width());
}

const DraggableElement* WrapperDE::getWrapElem() const
{
    return _innerDock.getDockedElem();
}

WrapperDE::~WrapperDE()
{

}
