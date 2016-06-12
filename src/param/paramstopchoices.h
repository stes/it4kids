#ifndef PARAMSTOPCHOICES_H
#define PARAMSTOPCHOICES_H

#include <QComboBox>

#include "param.h"

class ParamStopChoices : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamStopChoices(QWidget* parent);
    ~ParamStopChoices();

    bool setValue(const QString &);

protected:
    QString getString() const;
};

#endif // PARAMSTOPCHOICES_H
