#ifndef COMMANDDE_H
#define COMMANDDE_H

#include "dragableelement.h"

class CommandDE : public DragableElement
{
    Q_OBJECT
public:
    CommandDE(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
};

#endif // COMMANDDE_H
