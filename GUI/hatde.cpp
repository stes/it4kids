#include "hatde.h"

HatDE::HatDE(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget, QWidget* parent) :
     DragableElement(text, color, type, scriptAreaWidget, parent)
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
    return new HatDE(_text, _color, _type, _scriptAreaWidget, parent);
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
