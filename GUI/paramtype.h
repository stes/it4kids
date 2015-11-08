#ifndef PARAMTYPE_H
#define PARAMTYPE_H

#include <QComboBox>

#include "param.h"

class ParamType : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamType(QWidget* parent);

    QString getValue();

    ~ParamType();
};

#endif // PARAMTYPE_H
