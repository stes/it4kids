#ifndef DOCKINGAREA_H
#define DOCKINGAREA_H

#include <QRect>

class DraggableElement;
class Sprite;

class DockingArea
{
    bool _active;
    Sprite *_sprite;

public:
    DockingArea(Sprite *sprite);

    inline DraggableElement* getDockedElem() { return _dockedElem; }
    inline const DraggableElement* getDockedElem() const { return _dockedElem; }
    inline void setRect(const QRect& rect) { _dockingAreaGlobal = rect;}
    inline const QRect* getRect() const { return &_dockingAreaGlobal; }

    virtual void dock(DraggableElement* elem) = 0;
    virtual void undock() = 0;
    virtual inline DraggableElement* getParent() { return 0; }

    bool isActive() const { return _active; }
    void activate() { _active = true; }
    void deactivate() { _active = false; }

    virtual ~DockingArea();

protected:
    Sprite *getSprite() const { return _sprite; }

    QRect _dockingAreaGlobal;
    DraggableElement* _dockedElem;
};

#endif // DOCKINGAREA_H
