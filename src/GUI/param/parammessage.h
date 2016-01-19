#ifndef PARAMMESSAGE_H
#define PARAMMESSAGE_H

#include <QComboBox>

#include "param.h"

class ParamMessage : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamMessage(QWidget* parent);

    QString getValue();
    inline bool setValue(const QString &) {return 0; }

    ~ParamMessage();
};

#endif // PARAMMESSAGE_H
