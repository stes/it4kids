#ifndef REPORTERDE_H
#define REPORTERDE_H

#include "dragableelement.h"

class ReporterDE : public DragableElement
{
    Q_OBJECT
public:
    ReporterDE(const QString& text, const QColor& color, const QString& type, ScriptArea *scriptAreaWidget = 0, QWidget* parent = 0);

    void resize();
protected:
    DragableElement* getCurrentElement(QWidget* parent);
};

#endif // REPORTERDE_H
