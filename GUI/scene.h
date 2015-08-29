#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent* event);

signals:

public slots:
};

#endif // SCENE_H
