#ifndef PARAMCOSTUME_H
#define PARAMCOSTUME_H

#include <QObject>

#include "paramcombobox.h"

class Sprite;

class ParamCostume : public QObject, public ParamComboBox
{
    Q_OBJECT

    Sprite *_sprite;

public:
    ParamCostume(QWidget* parent, Sprite *sprite);
    virtual ~ParamCostume();

public slots:
    void updateCostumeList();
};
#endif // PARAMCOSTUME_H
