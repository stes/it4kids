#ifndef PARAMJOINWORDS_H
#define PARAMJOINWORDS_H

#include <QWidget>
#include <QHBoxLayout>

#include "param.h"
#include "paramstring.h"

class ParamJoinWords : public QWidget, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamJoinWords(QWidget* parent);
    ~ParamJoinWords();

protected:
    ParamString _first;
    ParamString _second;

    QHBoxLayout _layout;

    QString getString() const;
};

#endif // PARAMJOINWORDS_H
