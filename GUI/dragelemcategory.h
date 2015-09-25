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

#include "dragableelement.h"
#include "dragelemlist.h"

class ScriptArea;

typedef std::vector<DragableElement*> ElementList;

class DragElemCategory : public QWidget
{
    Q_OBJECT
public:
    explicit DragElemCategory(QString name, QColor color, QWidget *parent = 0);

    void toggleActive();
    void setElemListWidget(DragElemList* elemListWidget);
    void setScriptAreaWidget(QWidget* scriptAreaWidget);
protected:
    void paintEvent(QPaintEvent*);

    void mousePressEvent(QMouseEvent* event);

    ElementList _elemList;
    DragElemList* _elemListWidget;
    QWidget* _scriptAreaWidget;

    QColor _color;
    QLabel _label;
signals:

public slots:
};

#endif // DRAGELEMCATEGORY_H
