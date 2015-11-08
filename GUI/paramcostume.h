#ifndef PARAMCOSTUME_H
#define PARAMCOSTUME_H

#include <QComboBox>

#include "param.h"

class ParamCostume : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamCostume(QWidget* parent);

    QString getValue();

    ~ParamCostume();
};
#endif // PARAMCOSTUME_H
