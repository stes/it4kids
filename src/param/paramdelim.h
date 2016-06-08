#ifndef PARAMDELIM_H
#define PARAMDELIM_H

#include <QComboBox>

#include "param.h"

class ParamDelim : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamDelim(QWidget* parent);
    ~ParamDelim();

protected:
    QString getString() const;
};

#endif // PARAMDELIM_H
