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
        _parent->rearrangeLowerElems();
        DraggableElement *outer = elem->getOuter();
        if(outer)
            outer->updateSize();
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

    DraggableElement *outer = _dockedElem->getOuter();

    _dockedElem->getDock(Upper)->activate();
    _dockedElem->setPrevElem(0);
    _dockedElem->setCurrentDock(0);
    _dockedElem = 0;
    if(_type != Inner)
        _parent->setNextElem(0);

    activate();
    if(outer)
        outer->updateSize();

    if(_parent->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());
}

void ScriptDock::setDock(const QPoint& pos, int width)
{
    _dockingPos = pos;
    if(_type == Upper)
        setRect(QRect(pos + QPoint(0,-20), QSize(width, 25)));
    else if(_type == Lower)
        setRect(QRect(pos + QPoint(0,-5), QSize(width, 25)));
    else if(_type == Inner)
        setRect(QRect(pos, QSize(width, 20)));
}

ScriptDock::~ScriptDock()
{
}
