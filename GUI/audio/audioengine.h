#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <QObject>

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class Sprite;

class AudioEngine : public QObject
{
    Q_OBJECT
public:
    explicit AudioEngine(QWidget* parent = 0);

    void setCurrentSprite(Sprite* sprite);

    bool loadFile(const QString &fileName);

protected:
    Sprite* _currentSprite;

};

#endif // AUDIOENGINE_H
