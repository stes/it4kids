#ifndef COMMANDDE_H
#define COMMANDDE_H

#include "dragableelement.h"

class ScriptDock;

class CommandDE : public DragableElement
{
    friend class ScriptDock;
    Q_OBJECT
public:
    CommandDE(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();

    ~CommandDE();
protected:
    DragableElement* getCurrentElement(QWidget* parent);

    void moveEvent(QMoveEvent*);
    void mouseReleaseEvent(QMouseEvent* event);

    ScriptDock* _upperDock;
    ScriptDock* _lowerDock;
};

#endif // COMMANDDE_H
