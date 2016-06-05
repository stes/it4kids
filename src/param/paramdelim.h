#ifndef PARAMDELIM_H
#define PARAMDELIM_H

#include <QComboBox>

#include "param.h"

class ParamDelim : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamDelim(QWidget* parent);

    QString getValue();

    ~ParamDelim();
};

#endif // PARAMDELIM_H
