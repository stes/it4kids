#include "costumeselect.h"
#include "QDebug"

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
    for(CostumeVector::iterator costume = _currentSprite->getCostumeVector()->begin();
        costume != _currentSprite->getCostumeVector()->end(); costume++)
    {
        _layout.addWidget(*costume);
        (*costume)->show();
    }
}
