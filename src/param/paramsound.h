#ifndef PARAMSOUND_H
#define PARAMSOUND_H

#include <QComboBox>

#include "param.h"

class ParamSound : public QComboBox, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamSound(QWidget* parent);
    ~ParamSound();

public slots:
    void updateSoundList();

protected:
    QString getString() const;
};

#endif // PARAMSOUND_H
