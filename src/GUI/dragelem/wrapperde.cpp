#include "wrapperde.h"
#include "commandde.h"
#include "hatde.h"

WrapperDE::WrapperDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget, QWidget* parent) :
    DragableElement(identifier, text, color, type, scriptAreaWidget, parent), _label(new QWidget(this))
{
    QString spec(text);
    spec.remove("%c");

    _width = 0;
    parseText(spec, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(0, 0, 0, 0);

    _label->move(4, 3);
    _label->setLayout(&_layout);
    _label->show();

    _upperDock = new ScriptDock(scriptAreaWidget, ScriptDock::Upper, this);
    _lowerDock = new ScriptDock(scriptAreaWidget, ScriptDock::Lower, this);
    _innerDock = new ScriptDock(scriptAreaWidget, ScriptDock::Inner, this);

    resize();
}

DragableElement* WrapperDE::getCurrentElement(QWidget *parent)
{
    return new WrapperDE(_identifier, _text, _color, _type, _scriptAreaWidget, parent);
}

void WrapperDE::rearrangeUpperElems()
{
    rearrangeInnerElems();

    DragableElement* prevElem = _prevElem;

    if(prevElem)
    {
        prevElem->raise();
        prevElem->move(_upperDock->getRect()->topLeft() + prevElem->getUpperOffsett());
        prevElem->rearrangeUpperElems();
    }
}

void WrapperDE::rearrangeLowerElems()
{
    rearrangeInnerElems();

    resize();
    show();

    DragableElement* nextElem = _nextElem;

    if(nextElem)
    {
        nextElem->raise();
        nextElem->move(_lowerDock->getRect()->topLeft() + nextElem->getLowerOffsett());
        nextElem->rearrangeLowerElems();
    }
}

void WrapperDE::rearrangeInnerElems()
{
    DragableElement* innerElem = _innerDock->getDockedElem();

    if(innerElem)
    {
        innerElem->raise();
        innerElem->move(_innerDock->getRect()->topLeft() + innerElem->getLowerOffsett());
        innerElem->rearrangeLowerElems();
    }
}

void WrapperDE::resize()
{
    show();
    getLayoutSize();
    _path = QPainterPath();
    _path.lineTo(7, 0);
    _path.lineTo(11, 4);
    _path.lineTo(21, 4);
    _path.lineTo(25, 0);
    _path.lineTo(_width+5, 0);
    _path.lineTo(_width+5, _height+5);
    _path.lineTo(40, _height+5);
    _path.lineTo(37, 4+_height+5);
    _path.lineTo(26, 4+_height+5);
    _path.lineTo(22, _height+5);
    _path.lineTo(15, _height+5);

    _innerHeight = 0;
    DragableElement* inner = _innerDock->getDockedElem();
    while(inner)
    {
        _innerHeight += inner->getHeight()+5;
        inner = inner->getNextElem();
    }

    if(!_innerHeight) _innerHeight = 8;
    _path.lineTo(15, _height+_innerHeight+5);
    _path.lineTo(_width+20, _height+_innerHeight+5);
    _path.lineTo(_width+20, _height+22+_innerHeight+5);

    _path.lineTo(25, _height+22+_innerHeight+5);
    _path.lineTo(22, _height+22+_innerHeight+9);
    _path.lineTo(11, _height+22+_innerHeight+9);
    _path.lineTo(7, _height+22+_innerHeight+5);
    _path.lineTo(0, _height+22+_innerHeight+5);

    _layout.setSizeConstraint(QLayout::SetNoConstraint);
    setFixedSize(_width+5, 22+_innerHeight+_height+9);
    _label->setMinimumWidth(_width+5);

    _upperDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) - QPoint(0, 10), QSize(_width, _height)));
    _innerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(15, _height), QSize(_width, _height)));
    _lowerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height+22+_innerHeight), QSize(_width, _height)));

    hide();
}

void WrapperDE::removeChildDragElems()
{
    if(_innerDock->getDockedElem()) _innerDock->getDockedElem()->removeChildDragElems();
    if(_lowerDock->getDockedElem()) _lowerDock->getDockedElem()->removeChildDragElems();
    _scriptAreaWidget->removeFromDragElem(this);
    delete this;
}

void WrapperDE::moveEvent(QMoveEvent*)
{
    _upperDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) - QPoint(0, 10), QSize(_width, _height)));
    _innerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(15, _height), QSize(_width, _height)));
    _lowerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height+22+_innerHeight), QSize(_width, _height)));
}

DragableElement* WrapperDE::getWrapElem()
{
    return _innerDock->getDockedElem();
}

WrapperDE::~WrapperDE()
{

}
