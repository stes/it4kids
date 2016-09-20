#include "scriptdock.h"

#include "draggableelement.h"
#include "mainwindow.h"

extern MainWindow* sMainWindow;

ScriptDock::ScriptDock(Type type, Sprite *sprite, DraggableElement* parent) :
    DockingArea(sprite, parent), _type(type)
{
}

void ScriptDock::connect(DraggableElement *upper, DraggableElement *lower)
{
    _dockedElem = lower;
    lower->setCurrentDock(this);
    lower->setPrevElem(upper);
    if(_type != Inner)
        upper->setNextElem(lower);
}

bool ScriptDock::dock(DraggableElement* elem)
{
    ScriptDock *otherDock;

    if(_type == Upper && !elem->getNextElem())
    {
        otherDock = elem->getDock(Lower);
        if(!otherDock)
            return false;
        otherDock->connect(elem, _parent);
        _parent->rearrangeUpperElems();
    }
    else if((_type == Lower || _type == Inner) && !elem->getPrevElem())
    {
        otherDock = elem->getDock(Upper);
        if(!otherDock)
            return false;
        connect(_parent, elem);
        elem->getRoot()->rearrangeLowerElems();
    }
    else
        return false;

    otherDock->deactivate();
    deactivate();

    if(elem->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());
    return true;
}

void ScriptDock::undock()
{
    if((_type != Lower && _type != Inner) || !_dockedElem)
        return;

    _dockedElem->getDock(Upper)->activate();
    _dockedElem->setPrevElem(0);
    _dockedElem->setCurrentDock(0);
    _dockedElem = 0;
    if(_type != Inner)
        _parent->setNextElem(0);

    activate();
    _parent->getRoot()->rearrangeLowerElems();
    if(_parent->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());
}

ScriptDock::~ScriptDock()
{
}
