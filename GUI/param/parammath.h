#ifndef PARAMMATH_H
#define PARAMMATH_H

#include <QComboBox>

#include "param.h"

class ParamMath : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamMath(QWidget* parent);

    QString getValue();

    ~ParamMath();
};

#endif // PARAMMATH_H
