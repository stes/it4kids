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
    friend class MainWindow;
    Q_OBJECT
public:
    explicit DragElemCategory(DragElemList *elemListWidget, const QString& name, const QColor& color, QWidget *parent = 0);

    void toggleActive();
    void setElemListWidget(DragElemList* elemListWidget);
    void setScriptAreaWidget(ScriptArea *scriptAreaWidget);

    ~DragElemCategory();
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void showEvent(QShowEvent*);

    ElementList _elemList;
    DragElemList* _elemListWidget;
    ScriptArea* _scriptAreaWidget;

    QLabel _label;
    QColor _color;
};

#endif // DRAGELEMCATEGORY_H
