#ifndef FIGURE_H
#define FIGURE_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "wavfile.h"

class Costume;
class DragableElement;
class DockingArea;
class QImage;
class ScriptArea;
class WavFile;

typedef std::vector<DockingArea*> HitTestVector;
typedef std::vector<DragableElement*> DragElemVector;
typedef std::vector<Costume*> CostumeVector;
typedef std::vector<WavFile*> SoundVector;

class Sprite : public QWidget
{
    friend class ScriptArea;
    friend class AudioEngine;
    friend class MainWindow;
    Q_OBJECT
public:
    inline SoundVector* getSoundVector() {return &_soundVector;}
    inline void addSound(WavFile* sound) {_soundVector.push_back(sound);}
    inline void playSound(int index) {_soundVector[index]->play(); }
    inline CostumeVector* getCostumeVector() {return &_costumeVector;}
    inline void addCostume(Costume* costume) {_costumeVector.push_back(costume);}
    void setCurrentCostume(Costume* costume);
    inline Costume* getCurrentConstume() {return _costumeVector[_currentCostumeIndex]; }

    ~Sprite();
Q_SIGNALS:
    void currentCostumeChanged(Sprite* sprite);
protected:
    explicit Sprite(ScriptArea* scriptArea, const QString& name = "Sprite", QWidget *parent = 0);

    void mousePressEvent(QMouseEvent*);

    QString _name;
    QLabel _imageLabel;
    QLabel _label;
    QVBoxLayout _layout;
    int _currentCostumeIndex;

    HitTestVector _hitTestVector;
    DragElemVector _dragElemVector;
    SoundVector _soundVector;
    CostumeVector _costumeVector;

    ScriptArea* _scriptArea;
};

#endif // FIGURE_H
