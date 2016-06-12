#ifndef PARAMCOSTUME_H
#define PARAMCOSTUME_H

#include <QComboBox>

#include "param.h"

class Sprite;

class ParamCostume : public QComboBox, public ParamBaseStr
{
    Q_OBJECT

    Sprite *_sprite;

public:
    ParamCostume(QWidget* parent, Sprite *sprite);
    ~ParamCostume();

    bool setValue(const QString &);

public slots:
    void updateCostumeList();

protected:
    QString getString() const;
};
#endif // PARAMCOSTUME_H
