#ifndef PARAMDOCK_H
#define PARAMDOCK_H

#include "dragelem/draggableelement.h"
#include "dockingarea.h"

class ParamDock : public DockingArea
{
    QWidget* _widget;
public:
    ParamDock(Sprite *sprite, DraggableElement *elemParent, QWidget *widget, DraggableElement::Type type);
    virtual ~ParamDock();

    bool dock(DraggableElement* dragelem);
    void undock();

protected:
    DraggableElement::Type _type;
};

class DockWrapperWidget : public QWidget
{
    Q_OBJECT

    ParamDock _dock;
    QWidget* _innerWidget;

public:
    DockWrapperWidget(Sprite *sprite, DraggableElement *elemParent, QWidget *innerWidget, DraggableElement::Type type, QWidget* parent = 0);
    virtual ~DockWrapperWidget();

    ParamDock* getDock() { return &_dock; }

protected:
    void paintEvent(QPaintEvent*);
};

#endif // PARAMDOCK_H
