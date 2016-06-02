#include "scriptdock.h"

#include <QDebug>
#include <QPainter>

#include "commandde.h"
#include "dragableelement.h"
#include "hatde.h"
#include "wrapperde.h"

ScriptDock::ScriptDock(ScriptArea *scriptArea, Type type, DragableElement* parent) :
    DockingArea(), _type(type), _parent(parent), _active(false)
{
    _scriptArea = scriptArea;
    activate();
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

void ScriptDock::connect(DragableElement *upper, DragableElement *lower)
{
    _dockedElem = lower;
    lower->setCurrentDock(this);
    lower->setPrevElem(upper);
    if(_type != Inner)
        upper->setNextElem(lower);
}

void ScriptDock::dock(DragableElement* elem)
{
    QString elemClass(elem->metaObject()->className());
    ScriptDock *otherDock;

    if(_type == Upper && !elem->_nextElem)
    {
        if(elemClass == "CommandDE") otherDock = ((CommandDE*) elem)->_lowerDock;
        else if(elemClass == "WrapperDE") otherDock = ((WrapperDE*) elem)->_lowerDock;
        else if(elemClass == "HatDE") otherDock = ((HatDE*) elem)->_lowerDock;
        else return;

        otherDock->connect(elem, _parent);
        _parent->rearrangeUpperElems();
    }
    else if((_type == Lower || _type == Inner) && !elem->_prevElem)
    {
        if(elemClass == "CommandDE") otherDock = ((CommandDE*) elem)->_upperDock;
        else if(elemClass == "WrapperDE") otherDock = ((WrapperDE*) elem)->_upperDock;
        else return;

        connect(_parent, elem);
        elem->getRoot()->rearrangeLowerElems();
    }
    otherDock->deactivate();
    deactivate();

    if(elem->getRoot()->getType() == "hat")
        _scriptArea->reloadCode();
}

void ScriptDock::undock()
{
    if(_dockedElem)
    {
        _dockedElem->setPrevElem(0);
        _dockedElem->setCurrentDock(0);
        _dockedElem->resize();
        _dockedElem->show();
        _dockedElem = 0;
        if(_type != Inner)
        {
            _parent->setNextElem(0);
        }
        activate();
    }
    _parent->getRoot()->rearrangeLowerElems();
    if(_parent->getRoot()->getType() == "hat")
        _scriptArea->reloadCode();
}

ScriptDock::~ScriptDock()
{

}
