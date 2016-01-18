#include "sprite.h"
#include <QDebug>

#include <algorithm>
#include <QImage>
#include <QLabel>
#include <QPainter>
#include <QStyleOption>

#include "scriptarea.h"
#include "costume.h"

Sprite::Sprite(ScriptArea* scriptArea, const QString &name, QWidget *parent) : QWidget(parent),
    _name(name), _scriptArea(scriptArea)
{
    setFixedSize(73, 73);
    setLayout(&_layout);

    _layout.addWidget(&_imageLabel);
    _layout.addWidget(&_label);

    _label.setText(_name);
}

void Sprite::setCurrentCostume(Costume *costume)
{
    int i;
    for(i = 0; i < _costumeVector.size(); i++)
    {
        if (_costumeVector[i] == costume)
        {
            _currentCostumeIndex = i;
            emit currentCostumeChanged(this);
            return;
        }
    }
    addCostume(costume);
    _currentCostumeIndex = _costumeVector.size();
    emit currentCostumeChanged(this);
}

void Sprite::mousePressEvent(QMouseEvent*)
{
    _scriptArea->setCurrentSprite(this);
}

Sprite::~Sprite()
{

}

