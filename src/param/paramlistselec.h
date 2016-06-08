#ifndef PARAMLISTSELEC_H
#define PARAMLISTSELEC_H

#include <QComboBox>

#include "param.h"

class ParamListSelec : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamListSelec(QWidget* parent);
    ~ParamListSelec();

protected:
    QString getString() const;
};

#endif // PARAMLISTSELEC_H
