#ifndef PARAMPREDICATE_H
#define PARAMPREDICATE_H

#include <QPainterPath>
#include <QWidget>

#include "param.h"
#include "paramdock.h"

class PredicateWidget : public QWidget
{
    Q_OBJECT

    QPainterPath _path;
    QColor _color;

public:
    PredicateWidget(QColor color, QWidget *parent = 0);
    virtual ~PredicateWidget();

protected:
    void paintEvent(QPaintEvent*);
};

class ParamPredicate : public ParamBaseExp
{
    DockWrapperWidget* _dockWidget;
    PredicateWidget* _predicateWidget;

public:
    ParamPredicate(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent = 0);
    virtual ~ParamPredicate();

    QString getValue() const { return "None"; }
    QWidget* getWidget() { return _dockWidget; };

    const DraggableElement* getDragElem() const { return _dockWidget->getDock()->getDockedElem(); }
};

#endif // PARAMPREDICATE_H
