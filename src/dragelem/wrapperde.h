#ifndef WRAPPERDE_H
#define WRAPPERDE_H

#include "dragableelement.h"

class WrapperDE : public DragableElement
{
    Q_OBJECT
public:
    WrapperDE(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite = 0, QWidget* parent = 0);

    void resize();

    QPoint getUpperOffsett() const { return UPPEROFFSET - QPoint(0, 22+_innerHeight); }

    void rearrangeUpperElems();
    void rearrangeLowerElems();
    void rearrangeInnerElems();

    inline int getHeight() const {return _height+22+_innerHeight;}
    DragableElement* getWrapElem();

    virtual void removeChildDragElems();

    virtual ScriptDock *getDock(ScriptDock::Type type);

    ~WrapperDE();
protected:
    DragableElement* getCurrentElement(Sprite *sprite, QWidget* parent);

    virtual void moveEvent(QMoveEvent *event);

    int _innerHeight;
    QWidget* _label;

    ScriptDock _upperDock;
    ScriptDock _lowerDock;
    ScriptDock _innerDock;
};

#endif // WRAPPERDE_H
