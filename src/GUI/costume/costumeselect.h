#ifndef COSTUMESELECT_H
#define COSTUMESELECT_H

#include <QWidget>
#include <QVBoxLayout>

class Sprite;

class CostumeSelect : public QWidget
{
    Q_OBJECT
public:
    explicit CostumeSelect(QWidget *parent = 0);

public Q_SLOTS:
    void changeCurrentSprite(Sprite* sprite);
    void updateCostumeList();

protected:
    Sprite* _currentSprite;
    QVBoxLayout _layout;
};

#endif // COSTUMESELECT_H
