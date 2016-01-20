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
class MainWindow;

typedef std::vector<DockingArea*> HitTestVector;
typedef std::vector<DragableElement*> DragElemVector;
typedef std::vector<Costume*> CostumeVector;
typedef std::vector<WavFile*> SoundVector;

class Sprite : public QWidget
{
    Q_OBJECT
    friend class ScriptArea;
    friend class AudioEngine;
    friend class MainWindow;
    friend class Ui_MainWindow;
public:
    inline QString getName() {return _name;}
    inline SoundVector* getSoundVector() {return &_soundVector;}
    inline void addSound(WavFile* sound) {_soundVector.push_back(sound);}
    inline void playSound(int index) {_soundVector[index]->play(); }
    inline CostumeVector* getCostumeVector() {return &_costumeVector;}
    inline void addCostume(Costume* costume) {_costumeVector.push_back(costume);}

    inline Costume* getCurrentConstume() {return _costumeVector[_currentCostumeIndex]; }
    DragElemVector* getDragElemVector() {return &_dragElemVector;}
    ~Sprite();
signals:
    void spriteSelected(Sprite* sprite);
    void currentCostumeChanged(Sprite* sprite);

public slots:
    void setCurrentCostume(Costume* costume);

protected:
    explicit Sprite(const QString& name, MainWindow *parent = 0);
    explicit Sprite(MainWindow* parent = 0);
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
};

#endif // FIGURE_H
