#include "scene.h"

Scene::Scene(QWidget *parent) : QWidget(parent)
{

}

void Scene::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    painter.setBrush(Qt::red);
    painter.drawRect(contentsRect());
}
