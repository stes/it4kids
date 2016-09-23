#ifndef REPORTERDE_H
#define REPORTERDE_H

#include "draggableelement.h"

class ReporterDE : public DraggableElement
{
    Q_OBJECT
public:
    ReporterDE(const QString& identifier, const QString& text, const QColor& color, Sprite *sprite = 0, QWidget* parent = 0);

    virtual void removeChildDragElems();

    Type getType() const { return Reporter; };

    ~ReporterDE();
protected:
    DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    void resizeEvent(QResizeEvent*);
};

#endif // REPORTERDE_H
