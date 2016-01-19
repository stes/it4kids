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
    inline bool setValue(const QString &) {return 0; }

    ~ParamStopChoices();
};

#endif // PARAMSTOPCHOICES_H
