#include <QScreen>
#include <QApplication>
#include <QPainter>

#include "paramcolor.h"

ColorWidget::ColorWidget(QWidget* parent) : QWidget(parent), _color("#ff00ff"), _active(false)
{
    setFixedSize(15, 15);
}

ColorWidget::~ColorWidget()
{
}

void ColorWidget::mousePressEvent(QMouseEvent*)
{
    if(!_active)
    {
        _active = true;
        _activePixmap = QGuiApplication::primaryScreen()->grabWindow(0);
        grabMouse();
    }
}

void ColorWidget::mouseMoveEvent(QMouseEvent* event)
{
    if(_active)
    {
        _color = _activePixmap.toImage().pixel(mapToGlobal(event->pos()));
        update();
    }
}

void ColorWidget::mouseReleaseEvent(QMouseEvent *)
{
    if(_active)
    {
        _active = false;
        releaseMouse();
    }
}

void ColorWidget::paintEvent(QPaintEvent *)
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

ParamColor::ParamColor(QWidget *parent) : _colorWidget(new ColorWidget(parent))
{
}

bool ParamColor::setValue(const QString &val)
{
    _colorWidget->setColor(QColor(val));
    return true;
}

QString ParamColor::getString() const
{
    return _colorWidget->getColor().name();
}

ParamColor::~ParamColor()
{
}
