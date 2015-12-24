#ifndef PARAMINTERACTION_H
#define PARAMINTERACTION_H

#include <QComboBox>

#include "param.h"

class ParamInteraction : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamInteraction(QWidget* parent);

    QString getValue();

    ~ParamInteraction();
};

#endif // PARAMINTERACTION_H
