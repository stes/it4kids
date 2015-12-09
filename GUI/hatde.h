#ifndef HATDE_H
#define HATDE_H

#include "dragableelement.h"

class ScriptDock;

class HatDE : public DragableElement
{
    friend class ScriptDock;
    Q_OBJECT
public:
    HatDE(const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();
protected:
    DragableElement* getCurrentElement(QWidget* parent);

    void moveEvent(QMoveEvent *);
    void mouseReleaseEvent(QMouseEvent* event);

    ScriptDock* _lowerDock;
};

#endif // HATDE_H
