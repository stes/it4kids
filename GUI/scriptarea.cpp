#include "scriptarea.h"
#include "algorithm"

ScriptArea::ScriptArea(QWidget *parent) : QWidget(parent)
{

}

void ScriptArea::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("#dddede")));
    painter.drawRect(contentsRect());
}

void ScriptArea::addToHitTest(QWidget *widget)
{
    _hitTestVector.push_back(widget);
}

void ScriptArea::removeFromHitTest(QWidget *widget)
{
    _hitTestVector.erase(std::remove(_hitTestVector.begin(), _hitTestVector.end(), widget), _hitTestVector.end());
}

HitTestVector* ScriptArea::getHitTestVector()
{
    return &_hitTestVector;
}
