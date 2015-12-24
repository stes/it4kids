#ifndef WRAPPERDE_H
#define WRAPPERDE_H

#include "dragableelement.h"

class WrapperDE : public DragableElement
{
    friend class ScriptDock;
    Q_OBJECT
public:
    WrapperDE(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();

    ~WrapperDE();
protected:
    DragableElement* getCurrentElement(QWidget* parent);

    virtual void moveEvent(QMoveEvent *);
    virtual void paintEvent(QPaintEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

    int getNumberElements();
    int _numberElements;
    int _innerHeight;
    QWidget* _label;

    ScriptDock* _upperDock;
    ScriptDock* _lowerDock;
    ScriptDock* _innerDock;
};

#endif // WRAPPERDE_H
