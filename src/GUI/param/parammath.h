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
    inline bool setValue(const QString &) {return 0; }

    ~ParamMath();
};

#endif // PARAMMATH_H
