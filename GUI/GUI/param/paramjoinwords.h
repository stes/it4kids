#ifndef PARAMJOINWORDS_H
#define PARAMJOINWORDS_H

#include <QWidget>
#include <QHBoxLayout>

#include "param.h"
#include "paramstring.h"

class ParamJoinWords : public QWidget, public Param
{
    Q_OBJECT
public:
    ParamJoinWords(QWidget* parent);

    QString getValue();

    ~ParamJoinWords();
protected:
    ParamString _first;
    ParamString _second;

    QHBoxLayout _layout;
};

#endif // PARAMJOINWORDS_H
