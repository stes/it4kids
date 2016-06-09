#ifndef SCRIPTDOCK_H
#define SCRIPTDOCK_H

#include "dockingarea.h"

#define LOWEROFFSET QPoint(0, 5)
#define UPPEROFFSET QPoint(0, -8)
#define UPPEROFFSETHAT QPoint(0, -21)

class ScriptArea;

class ScriptDock : public DockingArea
{
    void connect(DragableElement *upper, DragableElement *lower);

public:
    enum Type
    {
        Upper,
        Lower,
        Inner
    };

    ScriptDock(Type type, Sprite *sprite, DragableElement *parent);

    inline DragableElement* getParent() {return _parent;}

    virtual void dock(DragableElement* elem);
    virtual void undock();

    ~ScriptDock();

protected:
    Type _type;
    DragableElement* _parent;
};

#endif // SCRIPTDOCK_H

