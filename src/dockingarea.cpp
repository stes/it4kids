#include "dockingarea.h"

#include "sprite.h"

DockingArea::DockingArea(Sprite *sprite, DraggableElement* parent)
    : _active(true), _sprite(sprite), _dockedElem(0), _parent(parent)
{
    if(_sprite)
        _sprite->addToHitTest(this);
}

DockingArea::~DockingArea()
{
    if(_sprite)
        _sprite->removeFromHitTest(this);
}
