#ifndef COMMANDDE_H
#define COMMANDDE_H

#include "draggableelement.h"

class ScriptDock;

class CommandDE : public DraggableElement
{
    Q_OBJECT
public:
    CommandDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite = 0, QWidget* parent = 0);

    void rearrangeUpperElems();
    void rearrangeLowerElems();

    virtual void removeChildDragElems();

    virtual ScriptDock *getDock(ScriptDock::Type type);
    void updateDocks();

    Type getType() const { return Command; };

    ~CommandDE();
protected:
    DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    void resizeEvent(QResizeEvent*);

    ScriptDock _upperDock;
    ScriptDock _lowerDock;
};

#endif // COMMANDDE_H
