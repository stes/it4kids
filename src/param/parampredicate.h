#ifndef PARAMPREDICATE_H
#define PARAMPREDICATE_H

#include <QPainterPath>
#include <QWidget>

#include "param.h"
#include "paramdock.h"

class PredicateWidget : public QWidget
{
    Q_OBJECT

    ParamDock _dock;

    QPainterPath _path;
    QColor _color;

public:
    PredicateWidget(Sprite *sprite, DraggableElement *elemParent, QColor color, QWidget *parent = 0);
    virtual ~PredicateWidget();

    ParamDock* getDock() { return &_dock; }

protected:
    void paintEvent(QPaintEvent*);
};

class ParamPredicate : public ParamBaseExp
{
    PredicateWidget* _dockWidget;

public:
    ParamPredicate(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent = 0);
    virtual ~ParamPredicate();

    QString getValue() const;
    QWidget* getWidget() { return _dockWidget; };

    const DraggableElement* getDragElem() const { return _dockWidget->getDock()->getDockedElem(); }
};

#endif // PARAMPREDICATE_H
