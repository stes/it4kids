#ifndef FIGURE_H
#define FIGURE_H

#include <vector>

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class Costume;
class DraggableElement;
class DockingArea;
class WavFile;

typedef std::vector<DockingArea*> DockVector;
typedef std::vector<DraggableElement*> DragElemVector;
typedef std::vector<Costume*> CostumeVector;
typedef std::vector<WavFile*> SoundVector;

class Sprite : public QWidget
{
    Q_OBJECT

public:
    explicit Sprite(const QString& name, QWidget* parent = 0);
    explicit Sprite(QWidget* parent = 0);

    inline const QString &getName() const { return _name; }

    inline const SoundVector* getSoundVector() const {return &_soundVector;}
    inline void addSound(WavFile* sound) {_soundVector.push_back(sound);}
    void playSound(int index);

    inline const CostumeVector* getCostumeVector() const {return &_costumeVector;}
    inline void addCostume(Costume* costume) {_costumeVector.push_back(costume);}

    void addElement(DraggableElement *element) { _dragElemVector.push_back(element); }
    void removeElement(DraggableElement *element);

    void addToHitTest(DockingArea* widget) { _hitTestVector.push_back(widget); }
    void removeFromHitTest(DockingArea* widget);

    void performHitTest(DraggableElement* elem);

    void OverrideParents();

    const Costume* getCurrentConstume() const { return _costumeVector[_currentCostumeIndex]; }
    const DragElemVector* getDragElemVector() const { return &_dragElemVector; }
    virtual ~Sprite();

signals:
    void spriteSelected(Sprite* sprite);
    void currentCostumeChanged(Sprite* sprite);

public slots:
    void setCurrentCostume(Costume* costume);

protected:
    void mousePressEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent*);

    QString _name;
    QLabel _imageLabel;
    QLabel _label;
    QVBoxLayout _layout;
    int _currentCostumeIndex;

    DockVector _hitTestVector;
    DragElemVector _dragElemVector;
    SoundVector _soundVector;
    CostumeVector _costumeVector;
};

#endif // FIGURE_H
