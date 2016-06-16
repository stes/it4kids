#ifndef PARAMSOUND_H
#define PARAMSOUND_H

#include <QObject>

#include "paramcombobox.h"

class ParamSound : public QObject, public ParamComboBox
{
    Q_OBJECT
public:
    ParamSound(QWidget* parent);
    virtual ~ParamSound();

public slots:
    void updateSoundList();
};

#endif // PARAMSOUND_H
