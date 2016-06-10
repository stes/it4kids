#ifndef DRAGELEMCATEGORY_H
#define DRAGELEMCATEGORY_H

#include <vector>

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QColor>
#include <QRect>
#include <QPainter>
#include <QLabel>
#include <QApplication>

#include "mainwindow.h"
#include "draggableelement.h"
#include "dragelemlist.h"

class ScriptArea;

typedef std::vector<DraggableElement*> ElementList;

class DragElemCategory : public QWidget
{
    Q_OBJECT
public:
    explicit DragElemCategory(DragElemList *elemListWidget, const QString& name, const QColor& color, QWidget *parent = 0);

    void toggleActive();
    void setElemListWidget(DragElemList* elemListWidget);

    QColor getColor() const { return _color; }
    ElementList *getElemList() { return &_elemList; }
    QString getName() const { return _label.text(); }

    ~DragElemCategory();
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void showEvent(QShowEvent*);

    ElementList _elemList;
    DragElemList* _elemListWidget;

    QLabel _label;
    QColor _color;
};

#endif // DRAGELEMCATEGORY_H
