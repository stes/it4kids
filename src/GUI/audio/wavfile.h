#ifndef WAVFILE_H
#define WAVFILE_H

#include <QLabel>
#include <QSound>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

class QSound;
class QImage;

typedef struct  WAV_HEADER
{
    //RIFF-Header
    char _RIFF[4];          // "RIFF"
    uint _riffSize;         // Filesize - 8
    char _WAVE[4];          // "WAVE"
    //fmt-Header
    char _fmt[4];            // "fmt "
    int _fmtSize;            // 16
    short _audioFormat;      // Audio format
    short _numOfChan;        // 1=Mono 2=Sterio
    int _samplesPerSec;      // Sampling Frequency in Hz
    int _bytesPerSec;        // bytes per second
    short _blockAlign;       // 2=16-bit mono, 4=16-bit stereo
    short _bitsPerSample;    // Number of bits per sample
    //data-chunk
    char _data[4];            // "data"
    int _dataSize;            // Sampled data length
} WavHeader;

class WavFile : public QWidget
{
    friend class AudioEngine;
    Q_OBJECT
public:
    WavFile(QWidget* parent = 0);

    bool open(const QString &fileName);
    /*inline const WavHeader* getWavHeader() {return &_wavHeader; }
    inline int getDataSize() {return _wavHeader._dataSize; }
    inline char* getDataPointer() {return _dataBuffer->data(); }*/
    inline void play() {_sound->play();}
    inline QString getName() {return _name;}
private:
    /*WavHeader _wavHeader;
    QByteArray* _dataBuffer;*/

    void mousePressEvent(QMouseEvent*);

    QSound* _sound;

    QVBoxLayout _layout;
    QPixmap _soundPixmap;
    QString _name;
    QLabel _nameLabel;
    QImage* _waveForm;
};

#endif // WAVFILE_H
