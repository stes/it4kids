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

#endif // PARAMDOCK_H
