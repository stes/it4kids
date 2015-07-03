#include "snapelement.h"

SnapElement::SnapElement(const QString &text, const QString &color, QWidget *parent) :
    QLabel(text, parent), _color(color), _dragged(false)
{
    setStyleSheet("background-color: " + color + "; background-image: url(:/snap/Resources/dragndrop.png); background-repeat: none;"
                  "border: none; margin-left: 5px; color: #ffffff;"
                  "padding-top: -2px; padding-left: 5px;"
                  "text-align: center; font-size: 10px; font-weight: bold;");
    setFixedHeight(24);
    setMinimumWidth(30);
    setMaximumWidth(180);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    hide();
}

SnapElement::~SnapElement()
{

}

void SnapElement::mousePressEvent(QMouseEvent* event)
{
    _offset = event->pos();
    if(!_dragged)
    {
        SnapElement* element = new SnapElement(text(), _color, QApplication::activeWindow());
        element->_dragged = true;
        element->setFixedHeight(24);
        element->setMinimumWidth(30);
        element->setMaximumWidth(180);
        element->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        element->grabMouse();
    }
}

void SnapElement::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(mapToParent(event->pos() - _offset));
        show();
    }
}

void SnapElement::mouseReleaseEvent(QMouseEvent *event)
{
    releaseMouse();
    if((event->globalPos().x() < 260 || event->globalPos().x() > 1380) || event->globalPos().y() < 145)
    {
        delete this;
    }
}
