#include "spriteselect.h"

#include "model/spritemodel.h"
#include "sprite.h"

SpriteSelect::SpriteSelect(QWidget *parent) : QWidget(parent), _spriteModel(0)
{
    setLayout(&_layout);
    show();
}

void SpriteSelect::setSpriteModel(const SpriteModel *model)
{
    _spriteModel = model;
    connect(_spriteModel, SIGNAL(updateSprites()), this, SLOT(updateSprites()));
}

void SpriteSelect::updateSprites()
{
    int i = 0;
    for(SpriteVector::const_iterator it = _spriteModel->getSpriteVector()->begin(); it != _spriteModel->getSpriteVector()->end(); it++)
    {
        _layout.addWidget(*it, i/4, i % 4, Qt::AlignLeft | Qt::AlignTop);
        i++;
    }
}

SpriteSelect::~SpriteSelect()
{
}
