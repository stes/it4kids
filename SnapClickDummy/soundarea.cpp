
#include "soundarea.h"

SoundArea::SoundArea(QWidget *parent) :
    QWidget(parent)
{
    _layout = new QHBoxLayout();
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    _soundListWidget = new QWidget(this);
    _soundListWidget->setFixedWidth(95);
    _layout->addWidget(_soundListWidget);

    _soundListLayout = new QVBoxLayout(this);
    _soundListLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    _soundListLayout->setContentsMargins(0, 0, 0, 0);
    _soundListLayout->setSpacing(5);
    _soundListWidget->setLayout(_soundListLayout);

    _newSound = new QLabel("Neuer Klang", this);
    _newSound->setFixedWidth(95);
    _newSound->setAlignment(Qt::AlignCenter);
    _newSound->setStyleSheet("color: #ffffff; font-weight: bold;");
    _soundListLayout->addWidget(_newSound);

    _newSoundButton = new SnapRoundButton(":snap/Resources/newsoundicon.png", this);
    _newSoundButton->setStyleSheet("margin-left: 26px;");
    _soundListLayout->addWidget(_newSoundButton);

    _sound = new QLabel("<html><img src=':/snap/Resources/sound.png' align='center'><p align='center' >TestSound</p></html>");
    _sound->setStyleSheet("color: #ffffff; margin-left: 5px;");
    _soundListLayout->addWidget(_sound);

    _drawingArea = new QLabel(this);
    _drawingArea->setStyleSheet("background-color: #ffffff");
    _drawingArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _layout->addWidget(_drawingArea);

    setLayout(_layout);
}

SoundArea::~SoundArea()
{

}


