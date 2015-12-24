#include "sprite.h"
#include <QDebug>

#include <QImage>
#include <QLabel>
#include <QPainter>
#include <QStyleOption>

#include "scriptarea.h"

Sprite::Sprite(ScriptArea* scriptArea, const QString &name, QWidget *parent) : QWidget(parent),
    _name(name), _scriptArea(scriptArea)
{
    setFixedSize(73, 73);
    setLayout(&_layout);

    _layout.addWidget(&_imageLabel);
    _layout.addWidget(&_label);

    _costumeVector.push_back(new QImage(":/Assets/libraryOn.png"));
    _imageLabel.setPixmap(QPixmap::fromImage(*_costumeVector[0]));
    _imageLabel.setFixedSize(70, 73);
    _label.setText(_name);
}

void Sprite::mousePressEvent(QMouseEvent*)
{
    _scriptArea->setCurrentSprite(this);
}

Sprite::~Sprite()
{

}

