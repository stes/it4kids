#ifndef PARAMNUMBER_H
#define PARAMNUMBER_H

#include <QLineEdit>

#include "param.h"

class ParamNumber : public QLineEdit, public Param
{
    Q_OBJECT
public:
    ParamNumber(QWidget *parent);

    QString getValue();

    ~ParamNumber();
};

#endif // PARAMNUMBER_H
