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
    inline bool setValue(const QString &) {return 0;}

    ~ParamCostume();
public slots:
    void updateCostumeList();
};
#endif // PARAMCOSTUME_H
