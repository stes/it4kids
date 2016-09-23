#ifndef HATDE_H
#define HATDE_H

#include "draggableelement.h"

class ScriptDock;

class HatDE : public DraggableElement
{
    Q_OBJECT
public:
    HatDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);
    QPoint getUpperOffsett() const { return UPPEROFFSETHAT; }

    void rearrangeLowerElems();
    virtual void removeChildDragElems();

    virtual ScriptDock *getDock(ScriptDock::Type type);
    void updateDocks();

    Type getType() const { return Hat; };
protected:
    DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    void resizeEvent(QResizeEvent*);

    ScriptDock _lowerDock;
};

#endif // HATDE_H
