#ifndef PARAMMESSAGE_H
#define PARAMMESSAGE_H

#include <QComboBox>

#include "param.h"

class ParamMessage : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamMessage(QWidget* parent);
    ~ParamMessage();

protected:
    QString getString() const;
};

#endif // PARAMMESSAGE_H
