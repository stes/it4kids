#ifndef SPRITEMODEL_H
#define SPRITEMODEL_H

#include <vector>

#include <QAbstractListModel>

class Sprite;
typedef std::vector<Sprite*> SpriteVector;

class SpriteModel : public QAbstractListModel
{
    Q_OBJECT
public:
    SpriteModel(QObject* parent = 0);
    virtual ~SpriteModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    void addSprite(Sprite* sprite);
    //void removeSprite(Sprite* sprite);
    const SpriteVector* getSpriteVector() const { return &_sprites; }

    void clear();

signals:
    void updateSprites();

private:
    SpriteVector _sprites;
};

#endif // SPRITEMODEL_H
