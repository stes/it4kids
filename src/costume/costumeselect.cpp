#include "costumeselect.h"

#include "costume.h"
#include "sprite.h"

CostumeSelect::CostumeSelect(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
    _layout.setContentsMargins(0, 5, 0, 0);
    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
}

void CostumeSelect::setCurrentSprite(Sprite* sprite)
{
    _currentSprite = sprite;
    updateCostumeList();
}

void CostumeSelect::updateCostumeList()
{
    int prevCount = _layout.count();
    for(int i = 0; i < prevCount; i++)
    {
        _layout.itemAt(0)->widget()->hide();
        _layout.removeItem(_layout.itemAt(0));
    }
    const CostumeVector *costumeVec = _currentSprite->getCostumeVector();
    for(CostumeVector::const_iterator it = costumeVec->begin(); it != costumeVec->end(); it++)
    {
        _layout.addWidget(*it);
        (*it)->show();
    }
}
