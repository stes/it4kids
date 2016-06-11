#ifndef SPRITESELECT_H
#define SPRITESELECT_H

#include <vector>

#include <QGridLayout>
#include <QWidget>

class Sprite;

typedef std::vector<Sprite*> SpriteVector;

class SpriteSelect : public QWidget
{
    Q_OBJECT
public:
    SpriteSelect(QWidget* parent = 0);

    inline void addSprite(Sprite* sprite) {_spriteVector.push_back(sprite); hide(); show();}
    inline void removeSprite(Sprite* sprite) {_spriteVector.erase(std::remove(_spriteVector.begin(), _spriteVector.end(), sprite), _spriteVector.end());}
    inline const SpriteVector* getSpriteVector() const {return &_spriteVector;}

    void clear();

    ~SpriteSelect();
protected:
    void showEvent(QShowEvent*);

    SpriteVector _spriteVector;

    QGridLayout _layout;
};

#endif // SPRITESELECT_H
