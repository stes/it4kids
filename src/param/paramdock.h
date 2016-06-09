#ifndef PARAMDOCK_H
#define PARAMDOCK_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>

#include "dockingarea.h"
#include "param.h"

class PredicateDE;
class DragableElement;

class ParamDock : public QWidget, public ParamBaseStr, public DockingArea
{
    Q_OBJECT

public:
    explicit ParamDock(QColor color, Sprite *sprite, QWidget *parent = 0);
    ~ParamDock();

    void dock(DragableElement* dragelem);
    void undock();

protected:
    QPainterPath _path;
    QColor _color;

    void paintEvent(QPaintEvent*);

    QString getString() const;
};

#endif // PARAMDOCK_H

