#include "scriptdock.h"

#include <QDebug>

#include "dragableelement.h"

ScriptDock::ScriptDock(ScriptArea *scriptArea, Type type, DragableElement* parent) :
    DockingArea(), _type(type), _parent(parent), _active(false)
{
    _scriptArea = scriptArea;
}

void ScriptDock::activate()
{
    if(!_active)
    {
        _scriptArea->addToHitTest(this);
        _active = true;
    }
}

void ScriptDock::deactivate()
{
    if(_active)
    {
        _scriptArea->removeFromHitTest(this);
        _active = false;
    }
}

void ScriptDock::dock(DragableElement* elem)
{
    if(_type == Upper)
    {
        elem->move(_dockingAreaGlobal.topLeft() + UPPEROFFSET);
        elem->setNextElem(_parent);
        _parent->setPrevElem(elem);
    }
    if(_type == Lower)
    {
        elem->move(_dockingAreaGlobal.topLeft() + LOWEROFFSET);
        elem->setPrevElem(_parent);
        _parent->setNextElem(elem);
    }
    deactivate();
    elem->setCurrentDock(this);
    _dockedElem = elem;
}

void ScriptDock::undock()
{
    if(_dockedElem)
    {
        if(_type == Upper)
        {
            _dockedElem->setNextElem(0);
            _parent->setPrevElem(0);
        }
        if(_type == Lower)
        {
            _dockedElem->setPrevElem(0);
            _parent->setNextElem(0);
        }
        activate();
        _dockedElem->setCurrentDock(0);
        _dockedElem = 0;
    }
}
