#include <QLabel>
#include <QPainter>
#include <QStyleOption>

#include "sprite.h"

#include "audio/wavfile.h"
#include "dragelem/draggableelement.h"
#include "costume/costume.h"
#include "mainwindow.h"
#include "scriptarea.h"

extern MainWindow* sMainWindow;

Sprite::Sprite(const QString &name, QWidget* parent) : QWidget(parent),
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
    connect(this, SIGNAL(spriteContextMenuRequested(QPoint,Sprite*)), sMainWindow, SLOT(spriteContextMenuRequested(QPoint,Sprite*)));
}

Sprite::Sprite(QWidget* parent) : QWidget(parent)
{
    connect(this, SIGNAL(spriteSelected(Sprite*)), parent, SLOT(changeCurrentSprite(Sprite*)));

    setFixedSize(73, 73);
    setLayout(&_layout);

    _layout.addWidget(&_imageLabel);
    _layout.addWidget(&_label);

    _name = QStringLiteral("Stage");
    _label.setText(_name);
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

void Sprite::playSound(int index)
{
    _soundVector[index]->play();
}

void Sprite::removeElement(DraggableElement *element)
{
    _dragElemVector.erase(std::remove(_dragElemVector.begin(), _dragElemVector.end(), element), _dragElemVector.end());
}

void Sprite::removeFromHitTest(DockingArea* widget)
{
    _hitTestVector.erase(std::remove(_hitTestVector.begin(), _hitTestVector.end(), widget), _hitTestVector.end());
}

void Sprite::performHitTest(DraggableElement* elem)
{
    QRect rectDE(elem->mapToGlobal(QPoint(0, 0)), QSize(elem->width(), elem->height()));
    for(DockVector::const_iterator it = _hitTestVector.begin(); it != _hitTestVector.end(); it++)
    {
        if((*it)->isActive() && (*it)->getRect()->intersects(rectDE) && (*it)->getParent()->getRoot() != elem)
        {
            if((*it)->dock(elem))
                return;
        }
    }
}

void Sprite::OverrideParents()
{
    for(DragElemVector::const_iterator it = _dragElemVector.begin(); it != _dragElemVector.end(); it++)
        (*it)->setParent(this);
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
    // TODO: this is not nice!
    OverrideParents();
}

