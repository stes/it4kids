#include "paramsound.h"

#include "mainwindow.h"
#include "costume.h"
#include "sprite.h"

extern MainWindow* _sMainWindow;

ParamSound::ParamSound(QWidget *parent) : QComboBox(parent)
{
    SoundVector* sV = _sMainWindow->getCurrentSprite()->getSoundVector();
    for(uint i = 0; i < sV->size(); i++)
    {
        addItem(sV->at(i)->getName());
    }
}

QString ParamSound::getValue()
{
    return currentText();
}

ParamSound::~ParamSound()
{

}


