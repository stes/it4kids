#ifndef PARAMDOCK_H
#define PARAMDOCK_H

#include <QWidget>
#include <QPainterPath>

#include "dockingarea.h"
#include "param.h"

class DockWidget : public QWidget, public DockingArea
{
    Q_OBJECT

    QPainterPath _path;
    QColor _color;

public:
    DockWidget(QColor color, Sprite *sprite, QWidget *parent = 0);
    virtual ~DockWidget();

    void dock(DraggableElement* dragelem);
    void undock();

    QString getDockedElemIdent() const;

protected:
    void paintEvent(QPaintEvent*);
};

class ParamDock : public ParamBaseStr
{
    DockWidget* _dockWidget;

public:
    ParamDock(QColor color, Sprite *sprite, QWidget *parent = 0);
    virtual ~ParamDock();

    QString getString() const;
    QWidget* getWidget() { return _dockWidget; };
};

#endif // PARAMDOCK_H

