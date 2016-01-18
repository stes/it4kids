#ifndef PARAMSOUND_H
#define PARAMSOUND_H

#include <QComboBox>

#include "param.h"

class ParamSound : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamSound(QWidget* parent);

    QString getValue();

    ~ParamSound();
};

#endif // PARAMSOUND_H
