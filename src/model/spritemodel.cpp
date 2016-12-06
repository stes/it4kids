#include "spritemodel.h"

#include "sprite.h"

SpriteModel::SpriteModel(QObject *parent) : QAbstractListModel(parent)
{
}

SpriteModel::~SpriteModel()
{
}

int SpriteModel::rowCount(const QModelIndex&) const
{
    return (int)_sprites.size();
}

QVariant SpriteModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= _sprites.size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        return _sprites.at(index.row())->getName();
    }
    return QVariant();
}

void SpriteModel::addSprite(Sprite* sprite)
{
    int size = (int)_sprites.size();
    beginInsertRows(QModelIndex(), size, size);
    _sprites.push_back(sprite);
    endInsertRows();
    emit updateSprites();
}

/*void SpriteModel::removeSprite(Sprite* sprite)
{
    _sprites.erase(std::remove(_sprites.begin(), _sprites.end(), sprite), _sprites.end());
}*/

void SpriteModel::clear()
{
    beginResetModel();
    while (!_sprites.empty())
    {
        delete _sprites.back();
        _sprites.pop_back();
    }
    endResetModel();
    emit updateSprites();
}
