#include "dragelemlist.h"
#include <QDebug>

DragElemList::DragElemList(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
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

