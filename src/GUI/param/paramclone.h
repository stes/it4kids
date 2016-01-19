#ifndef PARAMCLONE_H
#define PARAMCLONE_H

#include <QComboBox>

#include "param.h"

class ParamClone : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamClone(QWidget* parent);

    QString getValue();
    inline bool setValue(const QString &) {return 0; }

    ~ParamClone();
};

#endif // PARAMCLONE_H
