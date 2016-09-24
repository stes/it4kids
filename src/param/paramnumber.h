#ifndef PARAMNUMBER_H
#define PARAMNUMBER_H

#include <QLineEdit>

#include "param.h"
#include "paramdock.h"

class NumberWidget : public QLineEdit
{
	Q_OBJECT

    ParamDock _dock;

public:
    NumberWidget(Sprite *sprite, DraggableElement *elemParent, QWidget* parent = 0);
	virtual ~NumberWidget();

    ParamDock* getDock() { return &_dock; }

protected:
    void paintEvent(QPaintEvent*);
};

class ParamNumber : public ParamBaseNum
{
    NumberWidget* _lineEdit;

public:
    ParamNumber(Sprite *sprite, DraggableElement *elemParent, QWidget *parent = 0);
    virtual ~ParamNumber();

    bool setValue(const QString& value);
    QWidget* getWidget();

    const DraggableElement* getDragElem() const { return _lineEdit->getDock()->getDockedElem(); }

protected:
    double getNumber() const;
};

#endif // PARAMNUMBER_H
