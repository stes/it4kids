#ifndef PARAMTOUCH_H
#define PARAMTOUCH_H

#include <QComboBox>

#include "param.h"

class ParamTouch : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamTouch(QWidget* parent);
    ~ParamTouch();

protected:
    QString getString() const;
};

#endif // PARAMTOUCH_H
