#ifndef FIGURE_H
#define FIGURE_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "audio/wavfile.h"

class Costume;
class DraggableElement;
class DockingArea;
class QImage;
class ScriptArea;
class WavFile;
class MainWindow;

typedef std::vector<DockingArea*> HitTestVector;
typedef std::vector<DraggableElement*> DragElemVector;
typedef std::vector<Costume*> CostumeVector;
typedef std::vector<WavFile*> SoundVector;

class Sprite : public QWidget
{
    Q_OBJECT

public:
    explicit Sprite(const QString& name, QWidget* parent = 0);
    explicit Sprite(QWidget* parent = 0);

    inline QString getName() {return _name;}

    inline SoundVector* getSoundVector() {return &_soundVector;}
    inline void addSound(WavFile* sound) {_soundVector.push_back(sound);}
    inline void playSound(int index) {_soundVector[index]->play(); }

    inline CostumeVector* getCostumeVector() {return &_costumeVector;}
    inline void addCostume(Costume* costume) {_costumeVector.push_back(costume);}

    void addElement(DraggableElement *element) { _dragElemVector.push_back(element); }
    void removeElement(DraggableElement *element);

    void addToHitTest(DockingArea* widget) { _hitTestVector.push_back(widget); }
    void removeFromHitTest(DockingArea* widget);

    void performHitTest(DraggableElement* elem);

    void OverrideParents();

    inline Costume* getCurrentConstume() { return _costumeVector[_currentCostumeIndex]; }
    DragElemVector* getDragElemVector() { return &_dragElemVector; }
    virtual ~Sprite();

signals:
    void spriteSelected(Sprite* sprite);
    void currentCostumeChanged(Sprite* sprite);
    void spriteContextMenuRequested(const QPoint& pos, Sprite* elem);

public slots:
    void setCurrentCostume(Costume* costume);
    void contextMenuRequested(const QPoint& pos);

protected:
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
