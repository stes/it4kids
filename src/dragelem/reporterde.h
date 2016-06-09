#ifndef REPORTERDE_H
#define REPORTERDE_H

#include "dragableelement.h"

class ReporterDE : public DragableElement
{
    Q_OBJECT
public:
    ReporterDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);

    void resize();

    virtual void removeChildDragElems();

    ~ReporterDE();
protected:
    DragableElement* getCurrentElement(Sprite *sprite, QWidget* parent);
    void hitTest();
};

#endif // REPORTERDE_H
