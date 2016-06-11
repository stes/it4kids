#include "paramsound.h"

#include "audio/wavfile.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

typedef std::vector<WavFile*> SoundVector;

ParamSound::ParamSound(QWidget *parent) : QComboBox(parent)
{
    connect(sMainWindow, SIGNAL(newSound()), this, SLOT(updateSoundList()));
    updateSoundList();
}

QString ParamSound::getString() const
{
    return currentText();
}

ParamSound::~ParamSound()
{

}

void ParamSound::updateSoundList()
{
    const SoundVector *sndVec = sMainWindow->getCurrentSprite()->getSoundVector();
    for(SoundVector::const_iterator it = sndVec->begin(); it != sndVec->end(); it++)
    {
        addItem((*it)->getName());
    }
}


