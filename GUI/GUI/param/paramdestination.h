#ifndef PARAMDESTINATION_H
#define PARAMDESTINATION_H

#include <QComboBox>

#include "param.h"

class ParamDestination : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamDestination(QWidget* parent);

    QString getValue();

    ~ParamDestination();
};

#endif // PARAMDESTINATION_H
