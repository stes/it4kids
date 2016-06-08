#ifndef PARAMINTERACTION_H
#define PARAMINTERACTION_H

#include <QComboBox>

#include "param.h"

class ParamInteraction : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamInteraction(QWidget* parent);
    ~ParamInteraction();

protected:
    QString getString() const;
};

#endif // PARAMINTERACTION_H
