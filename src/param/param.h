#ifndef PARAM_H
#define PARAM_H

#include <QString>

class ParamBase
{
public:
    virtual ~ParamBase() { }

    virtual QString getValue() const = 0;
    virtual bool setValue(const QString&) { return 0; }
};

class ParamBaseStr : public ParamBase
{
public:
    virtual ~ParamBaseStr() { }

    QString getValue() const { return '"' + getString().toHtmlEscaped() + '"'; }

protected:
    virtual QString getString() const = 0;
};

class ParamBaseNum : public ParamBase
{
public:
    virtual ~ParamBaseNum() { }

    QString getValue() const { return QString::number(getNumber()); }

protected:
    virtual double getNumber() const = 0;
};

#endif // PARAM_H
