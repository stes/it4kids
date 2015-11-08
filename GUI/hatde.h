#ifndef HATDE_H
#define HATDE_H

#include "dragableelement.h"

class HatDE : public DragableElement
{
    Q_OBJECT
public:
    HatDE(const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
};

#endif // HATDE_H
