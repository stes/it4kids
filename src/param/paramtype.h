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
    inline bool setValue(const QString &) {return 0; }

    ~ParamType();
};

#endif // PARAMTYPE_H
