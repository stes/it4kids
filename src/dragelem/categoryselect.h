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

    CategoryList* getCategoryList() { return &_categoryList; }

    void setElemListWidget(DragElemList* elemListWidget);
    void show();

    ~CategorySelect();
protected:
    void paintEvent(QPaintEvent*);

    DragElemList* _elemListWidget;

    CategoryList _categoryList;
    QGridLayout _layout;
};

#endif // CATEGORYSELECT_H
