#ifndef PARAMVARIABLES_H
#define PARAMVARIABLES_H

#include <QComboBox>

#include "param.h"

class ParamVariables : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamVariables(QWidget* parent);

    QString getValue();

    ~ParamVariables();
};

#endif // PARAMVARIABLES_H
