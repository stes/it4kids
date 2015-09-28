#ifndef CATEGORYSELECT_H
#define CATEGORYSELECT_H

#include <vector>

#include <QWidget>
#include <QGridLayout>

#include "dragelemcategory.h"

class DragElemList;

typedef std::vector<DragElemCategory*> CategoryList;

class CategorySelect : public QWidget
{
    Q_OBJECT
public:
    explicit CategorySelect(QWidget *parent = 0);

    void setElemListWidget(DragElemList* elemListWidget);
    void setScriptAreaWidget(QWidget* scriptArea);
protected:
    void paintEvent(QPaintEvent*);

    DragElemList* _elemListWidget;
    QWidget* _scriptAreaWidget;

    CategoryList _categoryList;
    QGridLayout _layout;
signals:

public slots:
};

#endif // CATEGORYSELECT_H
