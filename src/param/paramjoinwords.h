#ifndef PARAMJOINWORDS_H
#define PARAMJOINWORDS_H

#include <QWidget>
#include <QHBoxLayout>

#include "param.h"
#include "paramstring.h"

class JoinWordsWidget : public QWidget
{
    Q_OBJECT

public:
    JoinWordsWidget(QWidget* parent);
    virtual ~JoinWordsWidget();

protected:
    ParamString _first;
    ParamString _second;

    QHBoxLayout _layout;
};

class ParamJoinWords : public ParamBaseStr
{
    JoinWordsWidget* _joinWordsWidget;

public:
    ParamJoinWords(QWidget* parent);
    virtual ~ParamJoinWords();

    QWidget* getWidget() { return _joinWordsWidget; };

protected:
    QString getString() const;
};

#endif // PARAMJOINWORDS_H
