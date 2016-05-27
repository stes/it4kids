#include "hatde.h"

HatDE::HatDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget, QWidget* parent) :
     DragableElement(identifier, text, color, type, scriptAreaWidget, parent)
{
    parseText(text, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(4, 4, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    _lowerDock = new ScriptDock(scriptAreaWidget, ScriptDock::Lower, this);

    resize();
}

DragableElement* HatDE::getCurrentElement(QWidget* parent)
{
    return new HatDE(_identifier, _text, _color, _type, _scriptAreaWidget, parent);
}

void HatDE::moveNextElems()
{
    DragableElement* nextElem = _nextElem;

    if(nextElem)
    {
        nextElem->raise();
        nextElem->move(_lowerDock->getRect()->topLeft() + nextElem->getLowerOffsett());
        nextElem->moveNextElems();
    }
}

void HatDE::resize()
{
    show();

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
    hide();
}

void HatDE::removeChildDragElems()
{
    if(_lowerDock->getDockedElem()) _lowerDock->getDockedElem()->removeChildDragElems();
    _scriptAreaWidget->removeFromDragElem(this);
    delete this;
}

void HatDE::moveEvent(QMoveEvent *)
{
    if(_lowerDock) _lowerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height+10), QSize(_width, _height)));
}

void HatDE::hitTest()
{
    _lowerDock->deactivate();
    _scriptAreaWidget->performHitTest(this);
    if(!_nextElem) _lowerDock->activate();
}
