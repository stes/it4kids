#include "categoryselect.h"

CategorySelect::CategorySelect(QWidget *parent) : QWidget(parent)
{
    DragElemCategory* bewegung = new DragElemCategory("Bewegung", QColor("#4A6CD4"), this);
    DragElemCategory* ereignisse = new DragElemCategory("Ereignisse", QColor("#c88330"), this);
    DragElemCategory* aussehen = new DragElemCategory("Aussehen", QColor("#8a55d7"), this);
    DragElemCategory* steuerung = new DragElemCategory("Steuerung", QColor("#e1a91a"), this);
    _categoryList.push_back(bewegung);
    _categoryList.push_back(ereignisse);
    _categoryList.push_back(aussehen);
    _categoryList.push_back(steuerung);

    setLayout(&_layout);
    _layout.setMargin(0);
    _layout.setSpacing(0);

    int i = 0;
    for(CategoryList::iterator category = _categoryList.begin(); category != _categoryList.end(); category++)
    {
        _layout.addWidget(*category, i/2, i % 2, 1, 1);
        i++;
    }

    setFixedHeight((i/2)*18);
}

void CategorySelect::setElemListWidget(DragElemList *elemListWidget)
{
    _elemListWidget = elemListWidget;
    for(CategoryList::iterator category = _categoryList.begin(); category != _categoryList.end(); category++)
    {
        (*category)->setElemListWidget(_elemListWidget);
    }
}

void CategorySelect::setScriptAreaWidget(QWidget* scriptArea)
{
    _scriptAreaWidget = scriptArea;
    for(CategoryList::iterator category = _categoryList.begin(); category != _categoryList.end(); category++)
    {
        (*category)->setScriptAreaWidget(_scriptAreaWidget);
    }
}

void CategorySelect::paintEvent(QPaintEvent* event)
{

}
