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

class ParamDock : public QWidget, public Param, public DockingArea
{
    Q_OBJECT
public:
    explicit ParamDock(QColor color, ScriptArea* scriptAreaWidget, QWidget *parent = 0);

    void dock(DragableElement* dragelem);
    void undock();

    QString getValue();

    ~ParamDock();
signals:

public slots:

protected:
    void paintEvent(QPaintEvent*);

    QPainterPath _path;
    QColor _color;

    ScriptArea* _scriptArea;
};

#endif // PARAMDOCK_H

