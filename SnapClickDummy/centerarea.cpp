#include "centerarea.h"

CenterArea::CenterArea(QWidget* parent) :
    QLabel(parent)
{
    _layout = new QGridLayout(this);
    _layout->setContentsMargins(0,0,0,0);
    _layout->setSpacing(5);
    setLayout(_layout);

    _freelyRotatable = new QPushButton(QIcon(":/snap/Resources/freelyRotatable.png"), "", this);
    _layout->addWidget(_freelyRotatable, 0, 0, 1, 1);
    _leftrightRotatable = new QPushButton(QIcon(":/snap/Resources/leftrightRotatable.png"), "", this);
    _layout->addWidget(_leftrightRotatable, 1, 0, 1, 1);
    _nonRotatable = new QPushButton(QIcon(":/snap/Resources/nonRotatable.png"), "", this);
    _layout->addWidget(_nonRotatable, 2, 0, 1, 1);

    _activeSprite = new QLabel();
    _activeSprite->setObjectName("activeSprite");
    _layout->addWidget(_activeSprite, 0, 1, 3, 1);

    _spriteName = new QTextEdit("SpriteName", this);
    _spriteName->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _spriteName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _layout->addWidget(_spriteName,0, 2, 2, 1);

    _draggable = new QCheckBox("greifbar", this);
    _layout->addWidget(_draggable, 2, 2, 1, 1);

    QSpacerItem* spacer = new QSpacerItem(0,0, QSizePolicy::Expanding);
    _layout->addItem(spacer, 0, 3, 3, 1);

    _centerTab = new QTabWidget();
    _centerTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _centerTab->addTab(new ScriptArea(), "Skripte");
    _centerTab->addTab(new CostumeArea(), "Kostüme");
    _centerTab->addTab(new SoundArea(), "Klänge");
    _layout->addWidget(_centerTab, 3, 0, 1, 4);
}

CenterArea::~CenterArea()
{

}
