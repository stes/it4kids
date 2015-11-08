#ifndef PARAMSTOPCHOICES_H
#define PARAMSTOPCHOICES_H

#include <QComboBox>

#include "param.h"

class ParamStopChoices : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamStopChoices(QWidget* parent);

    QString getValue();

    ~ParamStopChoices();
};

#endif // PARAMSTOPCHOICES_H
