#ifndef PARAMDESTINATION_H
#define PARAMDESTINATION_H

#include <QComboBox>

#include "param.h"

class ParamDestination : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamDestination(QWidget* parent);
    ~ParamDestination();

protected:
    QString getString() const;
};

#endif // PARAMDESTINATION_H
