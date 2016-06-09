#ifndef HATDE_H
#define HATDE_H

#include "dragableelement.h"

class ScriptDock;

class HatDE : public DragableElement
{
    Q_OBJECT
public:
    HatDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);

    void resize();

    QPoint getUpperOffsett() const { return UPPEROFFSETHAT; }

    void rearrangeLowerElems();
    virtual void removeChildDragElems();

    virtual ScriptDock *getDock(ScriptDock::Type type);
protected:
    DragableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    void moveEvent(QMoveEvent *);

    ScriptDock _lowerDock;
};

#endif // HATDE_H
