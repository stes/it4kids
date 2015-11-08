#ifndef PARAMDOCK_H
#define PARAMDOCK_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>

#include "param.h"
#include "dragableelement.h"

class PredicateDE;
class DragableElement;

class ParamDock : public QWidget, public Param
{
    Q_OBJECT
public:
    explicit ParamDock(QColor color, ScriptArea* scriptAreaWidget, QWidget *parent = 0);

    void dock(DragableElement* dragelem);

    QString getValue();

    ~ParamDock();
signals:

public slots:

protected:
    void paintEvent(QPaintEvent*);

    QPainterPath _path;
    QColor _color;

    DragableElement* _dockedElem;
    ScriptArea* _scriptArea;
};

#endif // PARAMDOCK_H

