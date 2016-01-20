#ifndef SCRIPTDOCK_H
#define SCRIPTDOCK_H

#include "dockingarea.h"

#define LOWEROFFSET QPoint(0, 5)
#define UPPEROFFSET QPoint(0, -8)
#define UPPEROFFSETHAT QPoint(0, -21)

class QPoint;
class ScriptArea;

class ScriptDock : public DockingArea
{
public:
    enum Type
    {
        Upper,
        Lower,
        Inner
    };

    ScriptDock(ScriptArea* scriptArea, Type type, DragableElement *parent);

    void activate();
    void deactivate();
    inline DragableElement* getParent() {return _parent;}

    virtual void dock(DragableElement* elem);
    virtual void undock();

    ~ScriptDock();
protected:
    ScriptArea* _scriptArea;
    Type _type;
    DragableElement* _parent;

    bool _active;
};

#endif // SCRIPTDOCK_H

