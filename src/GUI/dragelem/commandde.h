#ifndef COMMANDDE_H
#define COMMANDDE_H

#include "dragableelement.h"

class ScriptDock;

class CommandDE : public DragableElement
{
    friend class ScriptDock;
    friend class WrapperDE;
    Q_OBJECT
public:
    CommandDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void movePrevElems();
    void moveNextElems();

    void resize();

    virtual void removeChildDragElems();

    ~CommandDE();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
    void hitTest();

    void moveEvent(QMoveEvent*);

    ScriptDock* _upperDock;
    ScriptDock* _lowerDock;
};

#endif // COMMANDDE_H
