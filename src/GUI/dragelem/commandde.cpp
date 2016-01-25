#include "commandde.h"
#include "qdebug.h"
CommandDE::CommandDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget, QWidget* parent) :
        DragableElement(identifier, text, color, type, scriptAreaWidget, parent)
{
    parseText(text, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(4, 0, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    _upperDock = new ScriptDock(scriptAreaWidget, ScriptDock::Upper, this);
    _lowerDock = new ScriptDock(scriptAreaWidget, ScriptDock::Lower, this);

    resize();
}

DragableElement* CommandDE::getCurrentElement(QWidget *parent)
{
    return new CommandDE(_identifier, _text, _color, _type, _scriptAreaWidget, parent);
}

void CommandDE::resize()
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
    _path.lineTo(25, _height+5);
    _path.lineTo(22, _height+9);
    _path.lineTo(11, _height+9);
    _path.lineTo(7, _height+5);
    _path.lineTo(0, _height+5);

    setFixedSize(_width+5, _height+9);

    hide();
}

void CommandDE::moveEvent(QMoveEvent*)
{
    if(_upperDock) _upperDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) - QPoint(0, 10), QSize(_width, _height)));
    if(_lowerDock) _lowerDock->setRect(QRect(mapToGlobal(QPoint(0, 0)) + QPoint(0, _height), QSize(_width, _height)));
}

void CommandDE::hitTest()
{
    _lowerDock->deactivate();
    _upperDock->deactivate();
    _scriptAreaWidget->performHitTest(this);
    if(!_nextElem) _lowerDock->activate();
    if(!_prevElem) _upperDock->activate();
}

CommandDE::~CommandDE()
{

}
