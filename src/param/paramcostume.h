#ifndef PARAMCOSTUME_H
#define PARAMCOSTUME_H

#include <QComboBox>

#include "param.h"

class ParamCostume : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamCostume(QWidget* parent);
    ~ParamCostume();

public slots:
    void updateCostumeList();

protected:
    QString getString() const;
};
#endif // PARAMCOSTUME_H
