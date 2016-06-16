#ifndef PARAMSTRING_H
#define PARAMSTRING_H

#include "param.h"

class ParamString : public ParamBaseStr
{
    class QLineEdit* _lineEdit;

public:
    ParamString(QWidget* parent);
    virtual ~ParamString();

    bool setValue(const QString& value);
    QWidget* getWidget();

protected:
    QString getString() const;
};

#endif // PARAMSTRING_H
