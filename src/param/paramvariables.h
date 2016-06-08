#ifndef PARAMVARIABLES_H
#define PARAMVARIABLES_H

#include <QComboBox>

#include "param.h"

class ParamVariables : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamVariables(QWidget* parent);
    ~ParamVariables();

protected:
    QString getString() const;
};

#endif // PARAMVARIABLES_H
