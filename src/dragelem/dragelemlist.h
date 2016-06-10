#ifndef DRAGELEMLIST_H
#define DRAGELEMLIST_H

#include <vector>

#include <QScrollArea>
#include <QWidget>
#include <QVBoxLayout>

#include "draggableelement.h"

typedef std::vector<DraggableElement*> ElementList;

class DragElemList : public QScrollArea
{
    Q_OBJECT
public:
    explicit DragElemList(QWidget *parent = 0);

    void changeActiveList(ElementList* elemList);
protected:
    QWidget _elemListWidget;
    QVBoxLayout _layout;
};

#endif // DRAGELEMLIST_H
