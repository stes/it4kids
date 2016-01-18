#ifndef PARAMTOUCH_H
#define PARAMTOUCH_H

#include <QComboBox>

#include "param.h"

class ParamTouch : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamTouch(QWidget* parent);

    QString getValue();

    ~ParamTouch();
};

#endif // PARAMTOUCH_H
