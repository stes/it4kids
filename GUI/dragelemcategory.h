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
    explicit DragElemCategory(const QString& name, const QColor& color, QWidget *parent = 0);

    void toggleActive();
    void setElemListWidget(DragElemList* elemListWidget);
    void setScriptAreaWidget(QWidget* scriptAreaWidget);
protected:
    void paintEvent(QPaintEvent*);

    void mousePressEvent(QMouseEvent*);

    ElementList _elemList;
    DragElemList* _elemListWidget;
    QWidget* _scriptAreaWidget;

    QLabel _label;
    QColor _color;
signals:

public slots:
};

#endif // DRAGELEMCATEGORY_H
