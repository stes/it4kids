#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <QObject>

class Sprite;

class AudioEngine : public QObject
{
    Q_OBJECT
public:
    explicit AudioEngine(QWidget* parent = 0);

    bool loadFile(const QString &fileName);

public slots:
    void setCurrentSprite(Sprite* sprite);

protected:
    Sprite* _currentSprite;

};

#endif // AUDIOENGINE_H
