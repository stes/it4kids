#include <algorithm>

#include <QImage>
#include <QLabel>
#include <QPainter>
#include <QObject>
#include <QStyleOption>

#include "sprite.h"

#include "costume/costume.h"
#include "mainwindow.h"
#include "scriptarea.h"

extern MainWindow* _sMainWindow;

Sprite::Sprite(const QString &name, MainWindow* parent) : QWidget(parent),
    _name(name)
{
    connect(this, SIGNAL(spriteSelected(Sprite*)), parent, SLOT(changeCurrentSprite(Sprite*)));

    setFixedSize(73, 73);
    setLayout(&_layout);

    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    _layout.addWidget(&_imageLabel);
    _layout.addWidget(&_label);
    _label.setAlignment(Qt::AlignHCenter);

    _label.setText(_name);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequested(QPoint)));
    connect(this, SIGNAL(spriteContextMenuRequested(QPoint,Sprite*)), _sMainWindow, SLOT(spriteContextMenuRequested(QPoint,Sprite*)));
}

Sprite::Sprite(MainWindow* parent) : QWidget(parent)
{
    connect(this, SIGNAL(spriteSelected(Sprite*)), parent, SLOT(changeCurrentSprite(Sprite*)));

    setFixedSize(73, 73);
    setLayout(&_layout);

    _layout.addWidget(&_imageLabel);
    _layout.addWidget(&_label);

    _name = "Bühne";
    _label.setText(_name);
    Costume* costume = new Costume(this);
    costume->hide();
    _costumeVector.push_back(costume);
    setCurrentCostume(costume);
}

void Sprite::setCurrentCostume(Costume *costume)
{
    uint i;
    bool exists = false;
    for(i = 0; i < _costumeVector.size(); i++)
    {
        if (_costumeVector[i] == costume)
        {
            _currentCostumeIndex = i;
            emit currentCostumeChanged(this);
            exists = true;
        }
    }
    if(!exists)
    {
        addCostume(costume);
        _currentCostumeIndex = (int)_costumeVector.size() - 1;
    }
    _imageLabel.setPixmap(QPixmap::fromImage(_costumeVector[_currentCostumeIndex]->getImage()->scaled(40, 40)));
    emit currentCostumeChanged(this);
}

void Sprite::contextMenuRequested(const QPoint &pos)
{
    emit spriteContextMenuRequested(pos, this);
}

void Sprite::mousePressEvent(QMouseEvent*)
{
    emit spriteSelected(this);
}

Sprite::~Sprite()
{

}

