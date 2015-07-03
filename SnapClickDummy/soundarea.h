#ifndef SOUNDAREA
#define SOUNDAREA

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

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
    QLabel* _sound;
    QLabel* _drawingArea;
    QLabel* _newsound;
};

#endif // SOUNDAREA

