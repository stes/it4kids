#ifndef PARAMTYPE_H
#define PARAMTYPE_H

#include <QComboBox>

#include "param.h"

class ParamType : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamType(QWidget* parent);
    ~ParamType();

protected:
    QString getString() const;
};

#endif // PARAMTYPE_H
