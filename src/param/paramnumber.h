#ifndef PARAMNUMBER_H
#define PARAMNUMBER_H

#include <QLineEdit>

#include "param.h"
#include "paramdock.h"

class NumberWidget : public QLineEdit
{
	Q_OBJECT

public:
    NumberWidget(QWidget* parent = 0);
	virtual ~NumberWidget();
};

class ParamNumber : public ParamBaseNum
{
    DockWrapperWidget* _dockWidget;
    NumberWidget* _lineEdit;

public:
    ParamNumber(Sprite *sprite, DraggableElement *elemParent, QWidget *parent = 0);
    virtual ~ParamNumber();

    bool setValue(const QString& value);
    QWidget* getWidget() { return _dockWidget; };

    const DraggableElement* getDragElem() const { return _dockWidget->getDock()->getDockedElem(); }

protected:
    double getNumber() const;
};

#endif // PARAMNUMBER_H
