#ifndef SCRIPTAREA_H
#define SCRIPTAREA_H

#include <vector>

#include <QWidget>
#include <QPainter>

typedef std::vector<QWidget*> HitTestVector;

class ScriptArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScriptArea(QWidget *parent = 0);

    void paintEvent(QPaintEvent* event);

    void addToHitTest(QWidget* widget);
    void removeFromHitTest(QWidget* widget);
    HitTestVector* getHitTestVector();
signals:

public slots:

protected:
    HitTestVector _hitTestVector;
};

#endif // SCRIPTAREA_H
