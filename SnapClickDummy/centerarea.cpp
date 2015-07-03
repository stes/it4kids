#include "centerarea.h"

CenterArea::CenterArea(QWidget* parent) :
    QWidget(parent)
{
    setMinimumWidth(200);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("CenterArea {background-color:#373737; border: none;} QPushButton{border: none}");

    _layout = new QGridLayout(this);
    _layout->setContentsMargins(0,0,0,0);
    _layout->setSpacing(5);
    setLayout(_layout);
    _freelyRotatable = new QPushButton(QIcon(":/snap/Resources/freelyRotatable.png"), "", this);
    _freelyRotatable->setFixedSize(17, 17);
    _layout->addWidget(_freelyRotatable, 0, 0, 1, 1);
    _leftrightRotatable = new QPushButton(QIcon(":/snap/Resources/leftrightRotatable.png"), "", this);
    _leftrightRotatable->setFixedSize(17, 17);
    _layout->addWidget(_leftrightRotatable, 1, 0, 1, 1);
    _nonRotatable = new QPushButton(QIcon(":/snap/Resources/nonRotatable.png"), "", this);
    _nonRotatable->setFixedSize(17, 17);
    _layout->addWidget(_nonRotatable, 2, 0, 1, 1);

    _activeSprite = new QLabel();
    _activeSprite->setObjectName("activeSprite");
    _activeSprite->setFixedSize(60, 52);
    _activeSprite->setStyleSheet("QLabel#activeSprite{ border: none; border-image: url(:/snap/Resources/TurtleSprite.png) 0 0 0 0 stretch stretch;}");
    _activeSprite->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _layout->addWidget(_activeSprite, 0, 1, 3, 1);

    _spriteName = new QTextEdit("SpriteName", this);
    _spriteName->setStyleSheet("QTextEdit {background-color: #959595; border: none;}");
    _spriteName->setMaximumSize(200, 17);
    _spriteName->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _spriteName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _layout->addWidget(_spriteName,0, 2, 2, 1);
    _draggable = new QCheckBox("greifbar", this);
    _draggable->setStyleSheet("QCheckBox {color: #ffffff; margin-bottom: 5px;}");
    _layout->addWidget(_draggable, 2, 2, 1, 1);
    QSpacerItem* spacer = new QSpacerItem(0,0, QSizePolicy::Expanding);
    _layout->addItem(spacer, 0, 3, 3, 1);

    _centerTab = new QTabWidget();
    _centerTab->setMinimumSize(200, 200);
    _centerTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _centerTab->addTab(new ScriptArea(), "Skripte");
    _centerTab->addTab(new CostumeArea(), "Kostüme");
    _centerTab->addTab(new SoundArea(), "Klänge");
    _centerTab->setStyleSheet("QTabWidget::pane {border: none;}"
                              "QTabBar {min-width: 300px;}"
                              "QTabBar::tab {"
                              "                 background-image: url(:/snap/Resources/tabInactive.png); background-repeat: none;"
                              "                 width: 93px; height: 18px; margin-right: -20px;"
                              "                 color: #ffffff; font-weight: bold;"
                              "             }"
                              "QTabBar::tab:selected {background-image: url(:/snap/Resources/tab.png)}");
    _layout->addWidget(_centerTab, 3, 0, 1, 4);
}

CenterArea::~CenterArea()
{

}
