#include "reporterde.h"

ReporterDE::ReporterDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget, QWidget* parent) :
     DragableElement(identifier, text, color, type, scriptAreaWidget, parent)
{
    parseText(text, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(4, 4, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
}

DragableElement* ReporterDE::getCurrentElement(QWidget* parent)
{
    return new ReporterDE(_identifier, _text, _color, _type, _scriptAreaWidget, parent);
}

void ReporterDE::resize()
{
    DragableElement::resize();
    show();

    getLayoutSize();
    _path = QPainterPath();
    _path.moveTo(5, (_height+5)/2);
    _path.arcTo(0, 0, 10, _height+5, 90, 180);
    _path.moveTo(_width+5-5, (_height+5)/2);
    _path.arcTo(_width+5-10, 0, 10, _height+5, 270, 180);
    _path.moveTo(5, 0);
    _path.lineTo(_width+5-5, 0);
    _path.lineTo(_width+5-5, _height+5);
    _path.lineTo(5, _height+5);
    _path.lineTo(5, 0);
    setFixedSize(_width+10, _height+5);
    hide();
}

void ReporterDE::hitTest()
{

}

ReporterDE::~ReporterDE()
{

}

