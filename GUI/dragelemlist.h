#ifndef DRAGELEMLIST_H
#define DRAGELEMLIST_H

#include <vector>

#include <QWidget>
#include <QVBoxLayout>

#include "dragableelement.h"

typedef std::vector<DragableElement*> ElementList;

class DragElemList : public QWidget
{
    Q_OBJECT
public:
    explicit DragElemList(QWidget *parent = 0);

    void changeActiveList(ElementList* elemList);
protected:
    QVBoxLayout _layout;
signals:

public slots:
};

#endif // DRAGELEMLIST_H
