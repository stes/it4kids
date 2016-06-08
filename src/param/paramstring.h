#ifndef PARAMSTRING_H
#define PARAMSTRING_H

#include <QLineEdit>

#include "param.h"

class ParamString : public QLineEdit, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamString(QWidget* parent);
    ~ParamString();

    bool setValue(const QString& value);

protected:
    QString getString() const;
};

#endif // PARAMSTRING_H
