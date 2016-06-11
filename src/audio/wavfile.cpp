#include <QDebug>
#include <QPainter>
#include <QStringList>

#include "wavfile.h"

WavFile::WavFile(QWidget *parent) : QWidget(parent),
    _sound(0), _soundPixmap(":/Assets/soundlibraryOff.png"), _nameLabel(this)
{
    setLayout(&_layout);
    setFixedWidth(88);
    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    _layout.setContentsMargins(0, 0, 0, 0);

    QLabel* pixmapLabel = new QLabel(this);
    pixmapLabel->setPixmap(_soundPixmap.scaled(40, 40));
    pixmapLabel->setAlignment(Qt::AlignCenter);
    _layout.addWidget(pixmapLabel);

    _layout.addWidget(&_nameLabel);
    _nameLabel.setAlignment(Qt::AlignHCenter);
}

WavFile::~WavFile()
{
    if(_sound)
        delete _sound;
}

bool WavFile::open(const QString &fileName)
{
    QStringList list = fileName.split('/');
    _name = list.last();
    _name.truncate(_name.length() - 4);
    _nameLabel.setText(_name);
    _sound = new QSound(fileName, this);

    /*FILE* wavFile = fopen(fileName.toStdString().c_str(), "r");
    if (wavFile == 0)
    {
        qDebug() << "Unable to open WavFile";
        return false;
    }

    WavHeader wavHeader;
    fread(&wavHeader, 1, sizeof(WavHeader), wavFile);

    QByteArray dataBuffer(wavHeader._dataSize, 0);
    fread(dataBuffer.data(), 1, wavHeader._dataSize, wavFile);

    fclose(wavFile);

    _waveForm = new QImage(wavHeader._dataSize*8/wavHeader._bitsPerSample, 400, QImage::Format_ARGB32);
    QPainter painter(_waveForm);
    painter.setPen(Qt::black);

    int offset = (wavHeader._bitsPerSample/8)*16;
    int number = (wavHeader._dataSize*8/wavHeader._bitsPerSample) /16;
    qDebug() << wavHeader._audioFormat;
    for(int i = 0; i < number; i++)
    {
        const char* base = dataBuffer.constData();
        quint16 pcm = *(base + i * offset);
        pcm = pcm ? pcm -32767 : 0;
        qDebug()  << pcm;
        double value = ((float) pcm)/32768;
        painter.drawLine(i, 200, i, 200+value*200);
    }
    QLabel* label = new QLabel();
    label->setPixmap(QPixmap::fromImage(*_waveForm));
    label->show();*/

    return true;
}

void WavFile::mousePressEvent(QMouseEvent *)
{
    play();
}

