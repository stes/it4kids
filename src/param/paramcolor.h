#ifndef PARAMCOLOR_H
#define PARAMCOLOR_H

#include <QWidget>
#include <QColor>
#include <QPixmap>
#include <QMouseEvent>

#include "param.h"

class ParamColor : public QWidget, public ParamBaseStr
{
    Q_OBJECT
public:
    ParamColor(QWidget* parent);
    ~ParamColor();

    bool setValue(const QString &);

protected:
    QColor _color;
    bool _active;
    QPixmap _activePixmap;

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);

    QString getString() const;
};

#endif // PARAMCOLOR_H
