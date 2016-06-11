#include "soundselect.h"

#include "sprite.h"
#include "wavfile.h"

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
    const SoundVector *sndVec = _currentSprite->getSoundVector();
    for(SoundVector::const_iterator it = sndVec->begin(); it != sndVec->end(); it++)
    {
        _layout.addWidget(*it);
        (*it)->show();
    }
}

