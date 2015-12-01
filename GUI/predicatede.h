#ifndef PREDICATEDE_H
#define PREDICATEDE_H

#include "dragableelement.h"

class ParamDock;

class PredicateDE : public DragableElement
{
    Q_OBJECT
public:
    PredicateDE(const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
};

#endif // PREDICATEDE_H
