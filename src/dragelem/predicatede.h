#ifndef PREDICATEDE_H
#define PREDICATEDE_H

#include "draggableelement.h"

class ParamDock;

class PredicateDE : public DraggableElement
{
    Q_OBJECT
public:
    PredicateDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);

    void resize();

    virtual void removeChildDragElems();

    Type getType() const { return Predicate; };

    ~PredicateDE();
protected:
    DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent);
    void hitTest();
};

#endif // PREDICATEDE_H
