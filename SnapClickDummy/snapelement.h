#ifndef SNAPELEMENT
#define SNAPELEMENT

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QColor>

#include <QPainter>

class SnapElement : public QLabel
{
    Q_OBJECT

public:
    SnapElement(const QString& text, const QColor &color, const QString &maskPath, QWidget* parent = 0);
    ~SnapElement();

protected:
    QColor _color;
    QString _maskPath;
    QString _text;
    bool _dragged;
    QPoint _offset;
    int _width;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void paintEvent(QPaintEvent* event);
};

#endif // SNAPELEMENT

