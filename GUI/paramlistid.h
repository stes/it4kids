#ifndef PARAMLISTID_H
#define PARAMLISTID_H

#include <QComboBox>

#include "param.h"

class ParamListId : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamListId(QWidget* parent);

    QString getValue();

    ~ParamListId();
};

#endif // PARAMLISTID_H
