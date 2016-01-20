#include "predicatede.h"
#include "paramdock.h"
#include "QDebug"

PredicateDE::PredicateDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget, QWidget* parent) :
    DragableElement(identifier, text, color, type, scriptAreaWidget, parent)
{
    _currentDock = 0;
    parseText(text, this);
    _layout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _layout.setContentsMargins(10, 0, 0, 0);
    _layout.setSizeConstraint(QLayout::SetFixedSize);

    resize();
}

void PredicateDE::resize()
{
    show();

    getLayoutSize();
    _path = QPainterPath();
    _path.moveTo(0, (_height+4)/2);
    _path.lineTo(10, 0);
    _path.lineTo(_width+5, 0);
    _path.lineTo(_width+15, (_height+4)/2);
    _path.lineTo(_width+5, _height+4);
    _path.lineTo(10, _height+4);
    _path.lineTo(0, (_height+4)/2);
    _layout.setSizeConstraint(QLayout::SetNoConstraint);
    setFixedSize(_width+20, _height+4);

    hide();
}

DragableElement* PredicateDE::getCurrentElement(QWidget *parent)
{
    return new PredicateDE(_identifier, _text, _color, _type, _scriptAreaWidget, parent);
}

void PredicateDE::hitTest()
{
    _scriptAreaWidget->performHitTest(this);
}

PredicateDE::~PredicateDE()
{

}
