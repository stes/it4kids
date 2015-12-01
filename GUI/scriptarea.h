#ifndef SCRIPTAREA_H
#define SCRIPTAREA_H

#include <vector>

#include <QWidget>
#include <QPainter>

class DragableElement;
class DockingArea;
class Sprite;

typedef std::vector<DockingArea*> HitTestVector;
typedef std::vector<DragableElement*> DragElemVector;

class ScriptArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScriptArea(QWidget *parent = 0);

    void setCurrentSprite(Sprite* sprite);

    void addToHitTest(DockingArea* widget);
    void removeFromHitTest(DockingArea* widget);
    void performHitTest(DragableElement* elem);
    HitTestVector* getHitTestVector();

    void addToDragElem(DragableElement* elem);
    void removeFromDragElem(DragableElement* elem);
    DragElemVector* getDragElemVector();

protected:
    virtual void hideEvent(QHideEvent*);
    virtual void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent* event);

    Sprite* _currentSprite;
};

#endif // SCRIPTAREA_H
