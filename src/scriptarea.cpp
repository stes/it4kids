#include <QMenu>

#include "scriptarea.h"

#include "dragelem/draggableelement.h"
#include "sprite.h"

ScriptArea::ScriptArea(QWidget *parent) : QWidget(parent), _currentSprite(0)
{
}

void ScriptArea::setCurrentSprite(Sprite* sprite)
{
    hideElements();
    _currentSprite = sprite;
    if(isVisible())
        showElements();
}

void ScriptArea::hideElements()
{
    if(!_currentSprite)
        return;

    const DragElemVector *vec = _currentSprite->getDragElemVector();
    for(DragElemVector::const_iterator it = vec->begin(); it != vec->end(); it++)
    {
        (*it)->hide();
    }
}

void ScriptArea::showElements()
{
    if(!_currentSprite)
        return;

    const DragElemVector *vec = _currentSprite->getDragElemVector();
    for(DragElemVector::const_iterator it = vec->begin(); it != vec->end(); it++)
    {
        (*it)->show();
    }
}

void ScriptArea::hideEvent(QHideEvent*)
{
    hideElements();
}

void ScriptArea::showEvent(QShowEvent*)
{
    showElements();
}

void ScriptArea::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("#dddede")));
    painter.drawRect(contentsRect());
}

void ScriptArea::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu myMenu(this);
    myMenu.addAction(tr("clean up"));
    myMenu.addAction(tr("add comment"));
    myMenu.exec(event->globalPos());
}

ScriptArea::~ScriptArea()
{

}
