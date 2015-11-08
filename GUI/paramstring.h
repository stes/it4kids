#ifndef PARAMSTRING_H
#define PARAMSTRING_H

#include <QLineEdit>

#include "param.h"

class ParamString : public QLineEdit, public Param
{
    Q_OBJECT
public:
    ParamString(QWidget* parent);

    QString getValue();

    ~ParamString();
};

#endif // PARAMSTRING_H
