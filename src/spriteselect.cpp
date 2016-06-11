#include "spriteselect.h"

#include "sprite.h"

SpriteSelect::SpriteSelect(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
    show();
}

void SpriteSelect::showEvent(QShowEvent*)
{
    int i = 0;
    for(SpriteVector::const_iterator it = _spriteVector.begin(); it != _spriteVector.end(); ++it)
    {
        _layout.addWidget(*it, i/4, i % 4, Qt::AlignLeft | Qt::AlignTop);
        ++i;
    }
}

void SpriteSelect::clear()
{
    while (!_spriteVector.empty())
    {
        delete _spriteVector.back();
        _spriteVector.pop_back();
    }
}

SpriteSelect::~SpriteSelect()
{
}
