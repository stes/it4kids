#ifndef DOCKINGAREA_H
#define DOCKINGAREA_H

#include <QRect>

class DragableElement;
class Sprite;

class DockingArea
{
    bool _active;
    Sprite *_sprite;

public:
    DockingArea(Sprite *sprite);

    inline DragableElement* getDockedElem() {return _dockedElem; }
    inline void setRect(const QRect& rect) {_dockingAreaGlobal = rect;}
    inline QRect* getRect() {return &_dockingAreaGlobal; }

    virtual void dock(DragableElement* elem) = 0;
    virtual void undock() = 0;
    virtual inline DragableElement* getParent() { return 0; }

    bool isActive() const { return _active; }
    void activate() { _active = true; }
    void deactivate() { _active = false; }

    virtual ~DockingArea();

protected:
    QRect _dockingAreaGlobal;
    DragableElement* _dockedElem;
};

#endif // DOCKINGAREA_H
