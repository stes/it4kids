#include "wrapperde.h"
#include "commandde.h"
#include "hatde.h"
#include "qdebug.h"
WrapperDE::WrapperDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget, QWidget* parent) :
    DragableElement(identifier, text, color, type, scriptAreaWidget, parent), _numberElements(0), _label(new QWidget(this))
{
    QString spec(text);
    spec.remove("%c");

    _width = 0;
    parseText(spec, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(0, 0, 0, 0);

    _label->move(4, 3);
    _label->setLayout(&_layout);
    //_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
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

void WrapperDE::moveNextElems(QPoint offset)
{
    DragableElement* nextElem = _nextElem;
    while(nextElem)
    {
        nextElem->move(nextElem->pos() + offset);
        nextElem = nextElem->getNextElem();
    }
    nextElem = _innerDock->getDockedElem();
    while(nextElem)
    {
        nextElem->move(nextElem->pos() + offset);
        nextElem = nextElem->getNextElem();
    }
}

void WrapperDE::resize()
{
    DragableElement::resize();
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
    if(_nextElem) _nextElem->move(_lowerDock->getRect()->topLeft() + QPoint(0, 5));
    if(_innerDock->getDockedElem()) _innerDock->getDockedElem()->move(_innerDock->getRect()->topLeft() + QPoint(0, 5));

    hide();
}

void WrapperDE::moveEvent(QMoveEvent*)
{
    _upperDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) - QPoint(0, 10), QSize(_width, _height)));
    _innerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(15, _height), QSize(_width, _height)));
    _lowerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height+22+_innerHeight), QSize(_width, _height)));
}

int WrapperDE::getNumberElements()
{
    return _numberElements;
}

void WrapperDE::hitTest()
{
    _lowerDock->deactivate();
    _upperDock->deactivate();
    _innerDock->deactivate();
    DragableElement* next = _innerDock->getDockedElem();
    if(next)
    {
        while(next->getNextElem()) next = next->getNextElem();
        QString elemClass(next->metaObject()->className());
        if(elemClass == "CommandDE") ((CommandDE*) next)->_lowerDock->deactivate();
        else if(elemClass == "WrapperDE")
        {
            ((WrapperDE*) next)->_lowerDock->deactivate();
            ((WrapperDE*) next)->_innerDock->deactivate();
        }
        else if(elemClass == "HatDE") ((HatDE*) next)->_lowerDock->deactivate();
    }
    _scriptAreaWidget->performHitTest(this);

    if(!_innerDock->getDockedElem()) _innerDock->activate();
    if(!_nextElem) _lowerDock->activate();
    if(!_prevElem) _upperDock->activate();
}

DragableElement* WrapperDE::getWrapElem()
{
    return _innerDock->getDockedElem();
}

WrapperDE::~WrapperDE()
{

}
