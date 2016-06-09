#ifndef PREDICATEDE_H
#define PREDICATEDE_H

#include "dragableelement.h"

class ParamDock;

class PredicateDE : public DragableElement
{
    Q_OBJECT
public:
    PredicateDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);

    void resize();

    virtual void removeChildDragElems();

    ~PredicateDE();
protected:
    DragableElement* getCurrentElement(Sprite *sprite, QWidget* parent);
    void hitTest();
};

#endif // PREDICATEDE_H
