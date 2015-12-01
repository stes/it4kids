#ifndef SCRIPTDOCK_H
#define SCRIPTDOCK_H

#include "dockingarea.h"

#define LOWEROFFSET QPoint(0, 5)
#define UPPEROFFSET QPoint(0, -8)

class QPoint;
class ScriptArea;

class ScriptDock : public DockingArea
{
public:
    enum Type
    {
        Upper,
        Lower
    };

    ScriptDock(ScriptArea* scriptArea, Type type, DragableElement *parent);

    void activate();
    void deactivate();

    virtual void dock(DragableElement* elem);
    virtual void undock();
protected:
    ScriptArea* _scriptArea;
    Type _type;
    DragableElement* _parent;

    bool _active;
};

#endif // SCRIPTDOCK_H

