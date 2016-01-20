#ifndef PREDICATEDE_H
#define PREDICATEDE_H

#include "dragableelement.h"

class ParamDock;

class PredicateDE : public DragableElement
{
    Q_OBJECT
public:
    PredicateDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();

    ~PredicateDE();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
    void hitTest();
};

#endif // PREDICATEDE_H
