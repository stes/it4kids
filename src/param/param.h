#ifndef PARAM_H
#define PARAM_H

#include <QString>

class Param
{
public:
    virtual QString getValue() = 0;
    inline virtual bool setValue(const QString&) {return 0;}

    QString addQuotes(QString str) { return '"' + str.toHtmlEscaped() + '"'; }
};

#endif // PARAM_H
