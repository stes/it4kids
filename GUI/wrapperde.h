#ifndef WRAPPERDE_H
#define WRAPPERDE_H

#include "dragableelement.h"

class WrapperDE : public DragableElement
{
    Q_OBJECT
public:
    WrapperDE(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();
protected:
    DragableElement* getCurrentElement(QWidget* parent);

    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);

    int getNumberElements();
    int _numberElements;
    QWidget* _label;
};

#endif // WRAPPERDE_H
