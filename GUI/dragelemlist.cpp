#include "dragelemlist.h"
#include <QDebug>

DragElemList::DragElemList(QWidget *parent) : QWidget(parent)
{

}

void DragElemList::changeActiveList(ElementList *elemList)
{
    for(int i = 0; i < _layout.count(); i++)
    {
        _layout.removeWidget((QWidget*) _layout.itemAt(i));
    }
    qDebug() << elemList->size();
    for(ElementList::iterator element = elemList->begin(); element != elemList->end(); element++)
    {
        _layout.addWidget(*element);
        (*element)->show();
    }
}

