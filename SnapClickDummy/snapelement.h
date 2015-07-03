#ifndef SNAPELEMENT
#define SNAPELEMENT

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>

class SnapElement : public QLabel
{
    Q_OBJECT

public:
    SnapElement(const QString& text, const QString &color, QWidget* parent = 0);
    ~SnapElement();

protected:
    QString _color;
    bool _dragged;
    QPoint _offset;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // SNAPELEMENT

