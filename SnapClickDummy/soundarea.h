#ifndef SOUNDAREA
#define SOUNDAREA

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "snaproundbutton.h"

class SoundArea : public QWidget
{
    Q_OBJECT
public:
    SoundArea(QWidget* parent = 0);
    ~SoundArea();
protected:
    QHBoxLayout* _layout;

    QWidget* _soundListWidget;
    QVBoxLayout* _soundListLayout;

    QLabel* _newSound;
    SnapRoundButton* _newSoundButton;

    QLabel* _sound;
    QLabel* _drawingArea;
};

#endif // SOUNDAREA

