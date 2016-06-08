#ifndef PARAMNUMBER_H
#define PARAMNUMBER_H

#include <QLineEdit>

#include "param.h"

class ParamNumber : public QLineEdit, public ParamBaseNum
{
    Q_OBJECT
public:
    ParamNumber(QWidget *parent);
    ~ParamNumber();

    bool setValue(const QString& value);

protected:
    double getNumber() const;
};

#endif // PARAMNUMBER_H
