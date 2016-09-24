#include "mainwindow.h"
#include "paramdock.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

ParamDock::ParamDock(Sprite *sprite, DraggableElement *elemParent, QWidget *widget, DraggableElement::Type type)
    : DockingArea(sprite, elemParent), _widget(widget), _type(type)
{
}

bool ParamDock::dock(DraggableElement* elem)
{
    if(elem->getType() != _type)
        return false;

    // init docked element
    _dockedElem = elem;
    _dockedElem->setCurrentDock(this);
    _dockedElem->setParent(_parent);
    // remove dock
    int index = _parent->getParamLayout()->indexOf(_widget);
    _parent->getParamLayout()->removeWidget(_widget);
    // insert docked element
    _parent->getParamLayout()->insertWidget(index, _dockedElem);
    _widget->hide();

    deactivate();
    if(elem->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());

    return true;
}

void ParamDock::undock()
{
    // remove docked element
    int index = _parent->getParamLayout()->indexOf(_dockedElem);
    _parent->getParamLayout()->removeWidget(_dockedElem);
    QPoint pos = _dockedElem->mapToGlobal(QPoint(0, 0));
    // reset docked element
    _dockedElem->setCurrentDock(0);
    _dockedElem->setParent(sMainWindow);
    _dockedElem->move(pos);
    _dockedElem->show();
    _dockedElem = 0;
    // insert dock
    _parent->getParamLayout()->insertWidget(index, _widget);
    _widget->show();

    activate();
    if(_parent->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());
}

ParamDock::~ParamDock()
{
}
