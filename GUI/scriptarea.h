#ifndef SCRIPTAREA_H
#define SCRIPTAREA_H

#include <QWidget>
#include <QPainter>

class ScriptArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScriptArea(QWidget *parent = 0);

    void paintEvent(QPaintEvent* event);
signals:

public slots:
};

#endif // SCRIPTAREA_H
