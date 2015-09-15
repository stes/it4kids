#include "scriptarea.h"

ScriptArea::ScriptArea(QWidget *parent) : QWidget(parent)
{

}

void ScriptArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("#dddede")));
    painter.drawRect(contentsRect());
}
