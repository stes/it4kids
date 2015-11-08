#ifndef PARAMCOLOR_H
#define PARAMCOLOR_H

#include <QWidget>
#include <QColor>
#include <QPixmap>
#include <QMouseEvent>

#include "param.h"

class ParamColor : public QWidget, public Param
{
    Q_OBJECT
public:
    ParamColor(QWidget* parent);

    QString getValue();

    ~ParamColor();
protected:
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);

    QColor _color;
    bool _active;
    QPixmap _activePixmap;
};

#endif // PARAMCOLOR_H
