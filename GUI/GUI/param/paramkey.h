#ifndef PARAMKEY_H
#define PARAMKEY_H

#include <QComboBox>

#include "param.h"

class ParamKey : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamKey(QWidget* parent);

    QString getValue();

    ~ParamKey();
};

#endif // PARAMKEY_H
