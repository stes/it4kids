#ifndef PARAMSOUND_H
#define PARAMSOUND_H

#include <QComboBox>

#include "param.h"

class ParamSound : public QComboBox, public Param
{
    Q_OBJECT
public:
    ParamSound(QWidget* parent);

    QString getValue();
    inline bool setValue(const QString &) {return 0;}

    ~ParamSound();
public slots:
    void updateSoundList();
};

#endif // PARAMSOUND_H
