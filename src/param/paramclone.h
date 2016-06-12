#ifndef PARAMCLONE_H
#define PARAMCLONE_H

#include <QComboBox>

#include "param.h"

class ParamClone : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamClone(QWidget* parent);
    ~ParamClone();

    bool setValue(const QString &);

protected:
    QString getString() const;
};

#endif // PARAMCLONE_H
