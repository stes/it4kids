#include "dockingarea.h"

DockingArea::DockingArea() : _dockedElem(0)
{

}

DockingArea::~DockingArea()
{
    delete _dockedElem;
}
