#ifndef PREDICATEDE_H
#define PREDICATEDE_H

#include "draggableelement.h"

class PredicateDE : public DraggableElement
{
    Q_OBJECT
public:
    PredicateDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);

    virtual void removeChildDragElems();

    Type getType() const { return Predicate; };

    ~PredicateDE();
protected:
    DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    void resizeEvent(QResizeEvent*);
};

#endif // PREDICATEDE_H
