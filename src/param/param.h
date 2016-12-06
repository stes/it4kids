#ifndef PARAM_H
#define PARAM_H

#include <QColor>
#include <QString>

class QWidget;

class ParamBase
{
    QWidget *_myWidget;

public:
    enum Type
    {
        Number,
        String,
        Expression
    };

    // TODO: remove sprite and color
    static ParamBase* createParam(const QString &str,
                                  QWidget *parent = 0,
                                  class Sprite *sprite = 0,
                                  class DraggableElement *elem = 0,
                                  QColor color = QColor());

    virtual ~ParamBase() { }

    virtual QString getValue() const = 0;
    virtual bool setValue(const QString&) { return 0; }

    virtual void addOption(const QString &) { }

    virtual Type getType() const = 0;
    virtual QWidget* getWidget() = 0;

    virtual const class DraggableElement* getDragElem() const { return 0; };
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

class ParamBaseExp : public ParamBase
{
public:
    virtual ~ParamBaseExp() { }

    Type getType() const { return Expression; }
};

#endif // PARAM_H
