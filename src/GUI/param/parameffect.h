#ifndef PARAMEFFECT_H
#define PARAMEFFECT_H

#include <QComboBox>

#include "param.h"

class ParamEffect : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamEffect(QWidget* parent);

    QString getValue();
    inline bool setValue(const QString &) {return 0;}

    ~ParamEffect();
};

#endif // PARAMEFFECT_H
