#include <algorithm>

#include "scriptarea.h"

#include "dragelem/dragableelement.h"
#include "dockingarea.h"
#include "sprite.h"
#include "mainwindow.h"

ScriptArea::ScriptArea(QWidget *parent) : QWidget(parent), _currentSprite(0)
{

}

void ScriptArea::setMainWindow(MainWindow * main)
{
    _Mainwindow = main;
}

void ScriptArea::reloadCode()
{
    _Mainwindow->reloadCode();
}

void ScriptArea::setCurrentSprite(Sprite* sprite)
{
    if(_currentSprite)
    {
        for(DragElemVector::iterator it = _currentSprite->_dragElemVector.begin(); it != _currentSprite->_dragElemVector.end(); ++it)
        {
            (*it)->hide();
        }
    }

    _currentSprite = sprite;
    if(_currentSprite && isVisible())
    {
        for(DragElemVector::iterator it = _currentSprite->_dragElemVector.begin(); it != _currentSprite->_dragElemVector.end(); ++it)
        {
            (*it)->show();
        }
    }
}

void ScriptArea::addToHitTest(DockingArea* widget)
{
    _currentSprite->_hitTestVector.push_back(widget);
}

void ScriptArea::removeFromHitTest(DockingArea* widget)
{
    _currentSprite->_hitTestVector.erase(std::remove(_currentSprite->_hitTestVector.begin(), _currentSprite->_hitTestVector.end(), widget), _currentSprite->_hitTestVector.end());
}

void ScriptArea::performHitTest(DragableElement* elem)
{
    QRect rectDE(elem->mapToGlobal(QPoint(0, 0)), QSize(elem->width(), elem->height()));
    for(HitTestVector::iterator it = _currentSprite->_hitTestVector.begin(); it != _currentSprite->_hitTestVector.end(); it++)
    {
        if((*it)->getRect()->intersects(rectDE) && (*it)->getParent()->getRoot() != elem)
        {
            (*it)->dock(elem);
            break;
        }
    }
}

HitTestVector* ScriptArea::getHitTestVector()
{
    return &_currentSprite->_hitTestVector;
}

void ScriptArea::addToDragElem(DragableElement* elem)
{
    _currentSprite->_dragElemVector.push_back(elem);
}

void ScriptArea::removeFromDragElem(DragableElement* elem)
{
    _currentSprite->_dragElemVector.erase(std::remove(_currentSprite->_dragElemVector.begin(), _currentSprite->_dragElemVector.end(), elem), _currentSprite->_dragElemVector.end());
}

DragElemVector* ScriptArea::getDragElemVector()
{
    return &_currentSprite->_dragElemVector;
}

void ScriptArea::hideEvent(QHideEvent*)
{
    if(_currentSprite)
    {
        for(DragElemVector::iterator it = _currentSprite->_dragElemVector.begin(); it != _currentSprite->_dragElemVector.end(); ++it)
        {
            (*it)->hide();
        }
    }
}

void ScriptArea::showEvent(QShowEvent*)
{
    if(_currentSprite)
    {
        for(DragElemVector::iterator it = _currentSprite->_dragElemVector.begin(); it != _currentSprite->_dragElemVector.end(); ++it)
        {
            (*it)->show();
        }
    }
}

void ScriptArea::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("#dddede")));
    painter.drawRect(contentsRect());
}

ScriptArea::~ScriptArea()
{

}
