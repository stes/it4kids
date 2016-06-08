#ifndef PARAMDOCK_H
#define PARAMDOCK_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>

#include "dockingarea.h"
#include "param.h"

class PredicateDE;
class DragableElement;
class ScriptArea;

class ParamDock : public QWidget, public ParamBaseStr, public DockingArea
{
    Q_OBJECT
public:
    explicit ParamDock(QColor color, ScriptArea* scriptAreaWidget, QWidget *parent = 0);
    ~ParamDock();

    void dock(DragableElement* dragelem);
    void undock();

protected:
    QPainterPath _path;
    QColor _color;

    ScriptArea* _scriptArea;

    void paintEvent(QPaintEvent*);

    QString getString() const;
};

#endif // PARAMDOCK_H

