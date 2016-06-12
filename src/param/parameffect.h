#ifndef PARAMEFFECT_H
#define PARAMEFFECT_H

#include <QComboBox>

#include "param.h"

class ParamEffect : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamEffect(QWidget* parent);
    ~ParamEffect();

    bool setValue(const QString &);

protected:
    QString getString() const;
};

#endif // PARAMEFFECT_H
