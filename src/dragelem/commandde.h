#ifndef COMMANDDE_H
#define COMMANDDE_H

#include "dragableelement.h"

class ScriptDock;

class CommandDE : public DragableElement
{
    Q_OBJECT
public:
    CommandDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void rearrangeUpperElems();
    void rearrangeLowerElems();

    void resize();

    virtual void removeChildDragElems();

    virtual ScriptDock *getDock(ScriptDock::Type type);

    ~CommandDE();
protected:
    DragableElement* getCurrentElement(QWidget* parent);

    void moveEvent(QMoveEvent*);

    ScriptDock* _upperDock;
    ScriptDock* _lowerDock;
};

#endif // COMMANDDE_H
