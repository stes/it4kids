#ifndef PARAMKEY_H
#define PARAMKEY_H

#include "paramcombobox.h"

class ParamKey : public ParamComboBox
{
public:
    ParamKey(QWidget* parent);
    virtual ~ParamKey();
};

#endif // PARAMKEY_H
