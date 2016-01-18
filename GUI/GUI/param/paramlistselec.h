#ifndef PARAMLISTSELEC_H
#define PARAMLISTSELEC_H

#include <QComboBox>

#include "param.h"

class ParamListSelec : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamListSelec(QWidget* parent);

    QString getValue();

    ~ParamListSelec();
};

#endif // PARAMLISTSELEC_H
