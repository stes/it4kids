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
    inline bool setValue(const QString& value) {setText(value); return 1;}

    ~ParamNumber();
};

#endif // PARAMNUMBER_H
