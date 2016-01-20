#include "dragelemlist.h"
#include <QDebug>

DragElemList::DragElemList(QWidget *parent) : QScrollArea(parent), _elemListWidget(this)
{
    _elemListWidget.setObjectName("elemListWidget");
    _elemListWidget.setLayout(&_layout);
    _elemListWidget.setStyleSheet("");
    _layout.setSizeConstraint(QLayout::SetMinAndMaxSize);
    setWidget(&_elemListWidget);
}

void DragElemList::changeActiveList(ElementList *elemList)
{
    int prevCount = _layout.count();
    for(int i = 0; i < prevCount; i++)
    {
        _layout.itemAt(0)->widget()->hide();
        _layout.removeItem(_layout.itemAt(0));
    }
    for(ElementList::iterator element = elemList->begin(); element != elemList->end(); element++)
    {
         _layout.addWidget(*element);
        (*element)->show();
    }
}
