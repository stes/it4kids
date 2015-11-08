#include "wrapperde.h"
#include "qdebug.h"
WrapperDE::WrapperDE(const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget, QWidget* parent) :
    DragableElement(text, color, type, scriptAreaWidget, parent), _numberElements(0), _label(new QWidget(this))
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
    resize();
}

DragableElement* WrapperDE::getCurrentElement(QWidget *parent)
{
    return new WrapperDE(_text, _color, _type, _scriptAreaWidget, parent);
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

    int elements = getNumberElements();
    if(elements != 0)
    {
        _path.lineTo(15, _height+elements*20+5);
        _path.lineTo(_width+20, _height+elements*20+5);
        _path.lineTo(_width+20, _height+22+elements*20+5);
        _path.lineTo(0, _height+22+elements*20+5);
        _layout.setSizeConstraint(QLayout::SetNoConstraint);
        setFixedSize(_width+5, 22+elements*20+_height+5);
        _label->setMinimumWidth(_width+5);
    } else {
        _path.lineTo(15, _height+8+5);
        _path.lineTo(_width+20, _height+8+5);
        _path.lineTo(_width+20, _height+22+8+5);
        _path.lineTo(0, _height+22+8+5);
        setFixedSize(_width+20, _height+22+8+5);
        _layout.setSizeConstraint(QLayout::SetNoConstraint);
        setFixedSize(_width+5, 22+8+_height+5);
        _label->setMinimumWidth(_width+5);
    }

    hide();
}

void WrapperDE::paintEvent(QPaintEvent* event)
{
    DragableElement::paintEvent(event);
}

void WrapperDE::mousePressEvent(QMouseEvent* event)
{
    if(_dragged == true)
    {
        _numberElements++;
    }
    DragableElement::mousePressEvent(event);
    resize();
    show();
}

int WrapperDE::getNumberElements()
{
    return _numberElements;
}
