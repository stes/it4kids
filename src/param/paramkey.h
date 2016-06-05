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
    inline bool setValue(const QString &) {return 0;}

    ~ParamKey();
};

#endif // PARAMKEY_H
