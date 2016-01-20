#include "sprite.h"
#include <QDebug>

#include <algorithm>
#include <QImage>
#include <QLabel>
#include <QPainter>
#include <QObject>
#include <QStyleOption>

#include "costume.h"
#include "mainwindow.h"
#include "scriptarea.h"

Sprite::Sprite(const QString &name, MainWindow* parent) : QWidget(parent),
    _name(name)
{
    connect(this, SIGNAL(spriteSelected(Sprite*)), parent, SIGNAL(currentSpriteChanged(Sprite*)));

    setFixedSize(73, 73);
    setLayout(&_layout);

    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    _layout.addWidget(&_imageLabel);
    _layout.addWidget(&_label);
    _label.setAlignment(Qt::AlignHCenter);

    _label.setText(_name);
}

Sprite::Sprite(MainWindow* parent) : QWidget(parent)
{
    connect(this, SIGNAL(spriteSelected(Sprite*)), parent, SIGNAL(currentSpriteChanged(Sprite*)));

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
        _currentCostumeIndex = _costumeVector.size();
    }
    _imageLabel.setPixmap(QPixmap::fromImage(_costumeVector[_currentCostumeIndex]->getImage()->scaled(40, 40)));
    emit currentCostumeChanged(this);
}

void Sprite::mousePressEvent(QMouseEvent*)
{
    emit spriteSelected(this);
}

Sprite::~Sprite()
{

}

