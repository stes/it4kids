#ifndef WRAPPERDE_H
#define WRAPPERDE_H

#include <QVBoxLayout>

#include "draggableelement.h"

class WrapperDE : public DraggableElement
{
    Q_OBJECT

    QVBoxLayout* _layout;
    QSpacerItem* _innerSpace;

public:
    WrapperDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite = 0, QWidget* parent = 0);

    void resizeEvent();

    QPoint getUpperOffsett() const { return UPPEROFFSET - QPoint(0, 22+_innerHeight); }

    void rearrangeUpperElems();
    void rearrangeLowerElems();
    void rearrangeInnerElems();

    void updateSize();

    const DraggableElement* getWrapElem() const;

    virtual void removeChildDragElems();

    virtual ScriptDock *getDock(ScriptDock::Type type);
    void updateDocks();

    Type getType() const { return Wrapper; };

    ~WrapperDE();
protected:
    DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    void resizeEvent(QResizeEvent*);

    int _innerHeight;

    ScriptDock _upperDock;
    ScriptDock _lowerDock;
    ScriptDock _innerDock;
};

#endif // WRAPPERDE_H
