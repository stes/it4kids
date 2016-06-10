#ifndef PARAM_H
#define PARAM_H

#include <QString>

class ParamBase
{
public:
    enum Type
    {
        Number,
        String,
        Expression
    };

    virtual ~ParamBase() { }

    virtual QString getValue() const = 0;
    virtual bool setValue(const QString&) { return 0; }

    virtual Type getType() const = 0;
};

class ParamBaseStr : public ParamBase
{
    friend class SaveLoadClass;
public:
    virtual ~ParamBaseStr() { }

    QString getValue() const { return '"' + getString().toHtmlEscaped() + '"'; }

    Type getType() const { return String; };

protected:
    virtual QString getString() const = 0;
};

class ParamBaseNum : public ParamBase
{
    friend class SaveLoadClass;
public:
    virtual ~ParamBaseNum() { }

    QString getValue() const { return QString::number(getNumber()); }

    Type getType() const { return Number; };

protected:
    virtual double getNumber() const = 0;
};

#endif // PARAM_H
