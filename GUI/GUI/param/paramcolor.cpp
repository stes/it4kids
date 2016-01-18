#include "paramcolor.h"

#include <QGuiApplication>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

ParamColor::ParamColor(QWidget *parent) : QWidget(parent), _color("#ff00ff"), _active(false)
{
    setFixedSize(15, 15);
    #pragma message("Fix GetValue")
}

QString ParamColor::getValue()
{
    return QString("ParamColor");
}

ParamColor::~ParamColor()
{

}

void ParamColor::mousePressEvent(QMouseEvent*)
{
    if(!_active)
    {
        _active = true;
        _activePixmap = QGuiApplication::primaryScreen()->grabWindow(0);
        grabMouse();
    }
}

void ParamColor::mouseMoveEvent(QMouseEvent* event)
{
    if(_active)
    {
        _color = _activePixmap.toImage().pixel(mapToGlobal(event->pos()));
        update();
    }
}

void ParamColor::mouseReleaseEvent(QMouseEvent *)
{
    if(_active)
    {
        _active = false;
        releaseMouse();
    }
}

void ParamColor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // style(), width(), brush(), capStyle() and joinStyle().
    QPen pen(_color, 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(pen);

    // Brush
    QBrush brush;
    brush.setColor(_color);
    brush.setStyle(Qt::SolidPattern);

    // Draw polygon
    painter.fillRect(QRect(0, 0, 15, 15), brush);
    painter.setBackgroundMode(Qt::TransparentMode);
}
