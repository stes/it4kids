#include "categoryselect.h"
#include <QDebug>

CategorySelect::CategorySelect(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
    _layout.setMargin(0);
    _layout.setSpacing(0);
}

void CategorySelect::setElemListWidget(DragElemList *elemListWidget)
{
    _elemListWidget = elemListWidget;
    for(CategoryList::iterator category = _categoryList.begin(); category != _categoryList.end(); category++)
    {
        (*category)->setElemListWidget(_elemListWidget);
    }
}

void CategorySelect::setScriptAreaWidget(ScriptArea* scriptArea)
{
    _scriptAreaWidget = scriptArea;
    for(CategoryList::iterator category = _categoryList.begin(); category != _categoryList.end(); category++)
    {
        (*category)->setScriptAreaWidget(_scriptAreaWidget);
    }
}

void CategorySelect::show()
{
    int i = 0;
    for(CategoryList::iterator category = _categoryList.begin(); category != _categoryList.end(); ++category)
    {
        _layout.addWidget(*category, i/2, i % 2, 1, 1);
        ++i;
    }
    setFixedHeight((i/2)*18);
    QWidget::show();
}

void CategorySelect::paintEvent(QPaintEvent*)
{

}

CategorySelect::~CategorySelect()
{
    delete _elemListWidget;
}
