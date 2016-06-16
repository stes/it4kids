#ifndef PARAMMATH_H
#define PARAMMATH_H

#include "param.h"

class ParamMath : public ParamBase
{
    class QComboBox* _comboBox;

public:
    ParamMath(QWidget* parent);
    virtual ~ParamMath();

    bool setValue(const QString &);

    QString getValue() const;
    QWidget* getWidget();

    Type getType() const { return Expression; };
};

#endif // PARAMMATH_H
