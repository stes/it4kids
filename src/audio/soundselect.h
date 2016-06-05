#ifndef SOUNDSELECT_H
#define SOUNDSELECT_H

#include <QWidget>
#include <QVBoxLayout>

class Sprite;

class SoundSelect : public QWidget
{
    Q_OBJECT
public:
    explicit SoundSelect(QWidget *parent = 0);

public slots:
    void setCurrentSprite(Sprite* sprite);
    void updateSoundList();

protected:
    Sprite* _currentSprite;
    QVBoxLayout _layout;
};

#endif // SOUNDSELECT_H
