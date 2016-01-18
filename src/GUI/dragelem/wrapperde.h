#ifndef WRAPPERDE_H
#define WRAPPERDE_H

#include "dragableelement.h"

class WrapperDE : public DragableElement
{
    friend class ScriptDock;
    Q_OBJECT
public:
    WrapperDE(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();

    void moveNextElems(QPoint offset);
    inline int getHeight() {return _height+22+_innerHeight;}
    int getNumberElements();

    ~WrapperDE();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
    void hitTest();

    virtual void moveEvent(QMoveEvent *event);

    int _numberElements;
    int _innerHeight;
    QWidget* _label;

    ScriptDock* _upperDock;
    ScriptDock* _lowerDock;
    ScriptDock* _innerDock;
};

#endif // WRAPPERDE_H
