#include "paramsound.h"

#include "costume/costume.h"
#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* _sMainWindow;

ParamSound::ParamSound(QWidget *parent) : QComboBox(parent)
{
    connect(_sMainWindow, SIGNAL(newSound()), this, SLOT(updateSoundList()));
    updateSoundList();
}

QString ParamSound::getValue()
{
    return currentText();
}

ParamSound::~ParamSound()
{

}

void ParamSound::updateSoundList()
{
    SoundVector* sV = _sMainWindow->getCurrentSprite()->getSoundVector();
    for(uint i = 0; i < sV->size(); i++)
    {
        addItem(sV->at(i)->getName());
    }
}


