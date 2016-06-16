#ifndef PARAMCOLOR_H
#define PARAMCOLOR_H

#include <QWidget>
#include <QColor>
#include <QPixmap>
#include <QMouseEvent>

#include "param.h"

class ColorWidget : public QWidget
{
    Q_OBJECT

    QColor _color;
    bool _active;
    QPixmap _activePixmap;

public:
    ColorWidget(QWidget* parent);
    virtual ~ColorWidget();

    void setColor(QColor color) { _color = color; }
    QColor getColor() const { return _color; }

protected:
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
};

class ParamColor : public ParamBaseStr
{
    ColorWidget* _colorWidget;

public:
    ParamColor(QWidget* parent);
    virtual ~ParamColor();

    bool setValue(const QString &);
    QWidget* getWidget() { return _colorWidget; };

protected:
    QString getString() const;
};

#endif // PARAMCOLOR_H
