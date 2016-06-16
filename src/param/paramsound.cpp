#include <QComboBox>

#include "paramsound.h"

#include "audio/wavfile.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

typedef std::vector<WavFile*> SoundVector;

ParamSound::ParamSound(QWidget *parent) : ParamComboBox(parent)
{
    connect(sMainWindow, SIGNAL(newSound()), this, SLOT(updateSoundList()));
    updateSoundList();
}

ParamSound::~ParamSound()
{
}

void ParamSound::updateSoundList()
{
    _comboBox->clear();
    const SoundVector *sndVec = sMainWindow->getCurrentSprite()->getSoundVector();
    for(SoundVector::const_iterator it = sndVec->begin(); it != sndVec->end(); it++)
    {
        _comboBox->addItem((*it)->getName());
    }
}


