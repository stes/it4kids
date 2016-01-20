#include "soundselect.h"

#include "sprite.h"
#include "wavfile.h"

#include <QDebug>

SoundSelect::SoundSelect(QWidget *parent) : QWidget(parent)
{
    setLayout(&_layout);
    _layout.setContentsMargins(0, 5, 0, 0);
    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
}

void SoundSelect::setCurrentSprite(Sprite* sprite)
{
    _currentSprite = sprite;
    updateSoundList();
}

void SoundSelect::updateSoundList()
{
    int prevCount = _layout.count();
    for(int i = 0; i < prevCount; i++)
    {
        _layout.itemAt(0)->widget()->hide();
        _layout.removeItem(_layout.itemAt(0));
    }
    for(SoundVector::iterator sound = _currentSprite->getSoundVector()->begin();
        sound != _currentSprite->getSoundVector()->end(); sound++)
    {
        _layout.addWidget(*sound);
        (*sound)->show();
    }
}

