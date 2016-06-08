#ifndef PARAMLISTID_H
#define PARAMLISTID_H

#include <QComboBox>

#include "param.h"

class ParamListId : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamListId(QWidget* parent);
    ~ParamListId();

protected:
    QString getString() const;
};

#endif // PARAMLISTID_H
