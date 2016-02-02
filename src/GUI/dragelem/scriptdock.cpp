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

void ScriptDock::dock(DragableElement* elem)
{
    if(_type == Upper && !elem->_nextElem)
    {
        QString elemClass(elem->metaObject()->className());
        if(elemClass == "CommandDE")
        {
            QPoint oldPos = elem->pos();
            elem->move(_dockingAreaGlobal.topLeft() + UPPEROFFSET);
            elem->movePrevElems(-(oldPos - elem->pos()));
            ((CommandDE*) elem)->_lowerDock->deactivate();
            ((CommandDE*) elem)->_lowerDock->_dockedElem = _parent;
            _parent->setCurrentDock(((CommandDE*) elem)->_lowerDock);
            elem->setNextElem(_parent);
            _parent->setPrevElem(elem);

            deactivate();
        }
        if(elemClass == "HatDE")
        {
            elem->move(_dockingAreaGlobal.topLeft() + UPPEROFFSETHAT);
            ((HatDE*) elem)->_lowerDock->deactivate();
            (((HatDE*) elem)->_lowerDock->_dockedElem) = _parent;
            _parent->setCurrentDock(((HatDE*) elem)->_lowerDock);
            elem->setNextElem(_parent);
            _parent->setPrevElem(elem);
            deactivate();
        }
    }
    else if(_type == Lower && !elem->_prevElem)
    {
        elem->raise();
        QString elemClass(elem->metaObject()->className());
        QPoint oldPos = elem->pos();
        elem->move(_dockingAreaGlobal.topLeft() + LOWEROFFSET);
        elem->moveNextElems(-(oldPos - elem->pos()));
        if(elemClass == "CommandDE") ((CommandDE*) elem)->_upperDock->deactivate();
        else if(elemClass == "WrapperDE") ((WrapperDE*) elem)->_upperDock->deactivate();
        _dockedElem = elem;
        elem->setCurrentDock(this);
        elem->setPrevElem(_parent);
        _parent->setNextElem(elem);
        deactivate();
    }
    else if(_type == Inner && !elem->_prevElem)
    {
        elem->raise();
        QPoint oldPos = elem->pos();
        elem->move(_dockingAreaGlobal.topLeft() + LOWEROFFSET);
        elem->moveNextElems(-(oldPos - elem->pos()));
        QString elemClass(elem->metaObject()->className());
        if(elemClass == "CommandDE") ((CommandDE*) elem)->_upperDock->deactivate();
        else if(elemClass == "WrapperDE") ((WrapperDE*) elem)->_upperDock->deactivate();
        _dockedElem = elem;
        elem->setCurrentDock(this);
        elem->setPrevElem(_parent);
        deactivate();
    }
    elem->resize();
    elem->show();
    _parent->resize();
    _parent->show();
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
    _parent->resize();
    _parent->show();
}

ScriptDock::~ScriptDock()
{

}
