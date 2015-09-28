#ifndef DRAGABLEELEMENT_H
#define DRAGABLEELEMENT_H

#include <QWidget>
#include <QColor>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QApplication>

class DragableElement : public QWidget
{
    Q_OBJECT
public:
    DragableElement(const QString& text, const QColor& color, QWidget* scriptAreaWidget = 0, QWidget* parent = 0);
    ~DragableElement();

    void setScriptAreaWidget(QWidget* scriptAreaWidget);
protected:
    QColor _color;
    QString _text;
    QPoint _offset;
    bool _dragged;
    int _width;

    QWidget* _scriptAreaWidget;

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

    void paintEvent(QPaintEvent*);
};

#endif // DRAGABLEELEMENT_H
