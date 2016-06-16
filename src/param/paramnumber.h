#ifndef PARAMNUMBER_H
#define PARAMNUMBER_H

#include <QLineEdit>

#include "param.h"

class NumberWidget : public QLineEdit
{
	Q_OBJECT

public:
	NumberWidget(QWidget* parent) : QLineEdit(parent) { }
	virtual ~NumberWidget();
};

class ParamNumber : public ParamBaseNum
{
    class NumberWidget* _lineEdit;

public:
    ParamNumber(QWidget *parent);
    virtual ~ParamNumber();

    bool setValue(const QString& value);
    QWidget* getWidget();

protected:
    double getNumber() const;
};

#endif // PARAMNUMBER_H
