#ifndef DRAGABLEELEMENT_H
#define DRAGABLEELEMENT_H

#include <QWidget>
#include <QColor>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>

class DragableElement : public QWidget
{
    Q_OBJECT
public:
    DragableElement(const QString& text, const QColor& color, QWidget* parent = 0);
    ~DragableElement();

protected:
    QColor _color;
    QString _text;
    QPoint _offset;
    bool _dragged;
    int _width;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void paintEvent(QPaintEvent* event);
};

#endif // DRAGABLEELEMENT_H
