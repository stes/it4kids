#ifndef PARAMKEY_H
#define PARAMKEY_H

#include <QComboBox>

#include "param.h"

class ParamKey : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamKey(QWidget* parent);
    ~ParamKey();

    bool setValue(const QString &);

protected:
    QString getString() const;
};

#endif // PARAMKEY_H
