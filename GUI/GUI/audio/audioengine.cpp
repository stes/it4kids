#include "audio/audioengine.h"

#include "sprite.h"
#include "wavfile.h"
#include "qdebug.h"

#include <QAudioFormat>
#include <QAudioOutput>

AudioEngine::AudioEngine(QWidget *parent) : QObject(parent),
    _currentSprite(0)
{
}

void AudioEngine::setCurrentSprite(Sprite *sprite)
{
    _currentSprite = sprite;
}

bool AudioEngine::loadFile(const QString &fileName)
{
    WavFile* sound = new WavFile();
    if (!sound->open(fileName)) {
        #pragma message("Deal with failing to load Audio File")
        return false;
    }
    _currentSprite->_soundVector.push_back(sound);

    /*QPixmap waveForm(1000, 1000);
    waveForm.fill();
    QPainter painter;
    QPen black(Qt::black, 1);

    painter.begin(&waveForm);
    painter.setPen(black);
    short* base = (short*) sound->getDataPointer();
    for(int i = 0; i < sound->getDataSize()/2; i++)
    {
        float value = base[i] * 500 / 32768;
        painter.drawLine(i, 500, i, 500+value);
    }
    QLabel* label = new QLabel(0, Qt::Window);
    label->setPixmap(waveForm);
    label->show();

    QAudioFormat format;
    format.setSampleRate(sound->_wavHeader._samplesPerSec);
    format.setChannelCount(sound->_wavHeader._numOfChan);
    format.setSampleSize(sound->_wavHeader._bitsPerSample);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioOutput* audio = new QAudioOutput(format);
    QBuffer buffer(sound->_dataBuffer);
    audio->start(&buffer);*/
    return true;
}

