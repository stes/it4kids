#include "spriteselect.h"
#include <QDebug>
#include "sprite.h"

SpriteSelect::SpriteSelect(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
    show();

}

void SpriteSelect::showEvent(QShowEvent*)
{
    int i = 0;
    for(SpriteVector::iterator it = _spriteVector.begin(); it != _spriteVector.end(); ++it)
    {
        _layout.addWidget(*it, i/5, i % 5, Qt::AlignLeft | Qt::AlignTop);
        ++i;
    }
}

SpriteSelect::~SpriteSelect()
{

}
