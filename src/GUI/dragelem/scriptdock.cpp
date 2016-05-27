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

bool ScriptDock::dock(DragableElement* elem)
{
    QString elemClass(elem->metaObject()->className());

    if(_type == Upper && !elem->_nextElem)
    {
        ScriptDock *lower;
        if(elemClass == "CommandDE") lower = ((CommandDE*) elem)->_lowerDock;
        else if(elemClass == "WrapperDE") lower = ((WrapperDE*) elem)->_lowerDock;
        else if(elemClass == "HatDE") lower = ((HatDE*) elem)->_lowerDock;
        else return false;

        lower->deactivate();
        lower->_dockedElem = _parent;
        _parent->setCurrentDock(lower);
        elem->setNextElem(_parent);
        _parent->setPrevElem(elem);
        _parent->movePrevElems();
        elem->getRoot()->moveNextElems();
        deactivate();
    }
    else if(_type == Lower && !elem->_prevElem)
    {
        ScriptDock *upper;
        if(elemClass == "CommandDE") upper = ((CommandDE*) elem)->_upperDock;
        else if(elemClass == "WrapperDE") upper = ((WrapperDE*) elem)->_upperDock;
        else return false;

        upper->deactivate();
        _dockedElem = elem;
        elem->setCurrentDock(this);
        elem->setPrevElem(_parent);
        _parent->setNextElem(elem);
        elem->getRoot()->moveNextElems();
        deactivate();
    }
    else if(_type == Inner && !elem->_prevElem)
    {
        ScriptDock *upper;
        if(elemClass == "CommandDE") upper = ((CommandDE*) elem)->_upperDock;
        else if(elemClass == "WrapperDE") upper = ((WrapperDE*) elem)->_upperDock;
        else return false;

        upper->deactivate();
        _dockedElem = elem;
        elem->setCurrentDock(this);
        elem->setPrevElem(_parent);
        elem->getRoot()->moveNextElems();
        deactivate();
    }
    return elem->getRoot()->getType() == "hat";
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
    _parent->getRoot()->moveNextElems();
    if(_parent->getRoot()->getType() == "hat")
        _scriptArea->reloadCode();
}

ScriptDock::~ScriptDock()
{

}
