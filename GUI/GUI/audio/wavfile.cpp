#include "wavfile.h"

#include <iostream>

#include <QDebug>
#include <QStringList>

WavFile::WavFile(QWidget *parent) : QWidget(parent),
    _soundPixmap(":/Assets/soundlibraryOff.png"), _nameLabel(this)
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
}

bool WavFile::open(const QString &fileName)
{
    QStringList list = fileName.split("/");
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

    fread(&_wavHeader, 1, sizeof(WavHeader), wavFile);

    _dataBuffer = new QByteArray(_wavHeader._dataSize, 0);
    fread(_dataBuffer->data(), 1, _wavHeader._dataSize, wavFile);

    fclose(wavFile);*/

    return true;
}

