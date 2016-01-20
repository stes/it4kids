#ifndef PARAMDIRECTION_H
#define PARAMDIRECTION_H

#include <QComboBox>

#include "param.h"

class ParamDirection : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamDirection(QWidget* parent);

    QString getValue();
    inline bool setValue(const QString &) {return 0;}

    ~ParamDirection();
};

#endif // PARAMDIRECTION_H
