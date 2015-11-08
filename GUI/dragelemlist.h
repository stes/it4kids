#ifndef DRAGELEMLIST_H
#define DRAGELEMLIST_H

#include <vector>

#include <QScrollArea>
#include <QWidget>
#include <QVBoxLayout>

#include "dragableelement.h"

typedef std::vector<DragableElement*> ElementList;

class DragElemList : public QScrollArea
{
    Q_OBJECT
public:
    explicit DragElemList(QWidget *parent = 0);

    void changeActiveList(ElementList* elemList);
protected:
    QWidget _elemListWidget;
    QVBoxLayout _layout;
signals:

public slots:
};

#endif // DRAGELEMLIST_H
