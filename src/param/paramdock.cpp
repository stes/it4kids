#include <QPainter>

#include "dragelem/draggableelement.h"
#include "mainwindow.h"
#include "paramdock.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

DockWidget::DockWidget(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent)
    : QWidget(parent), DockingArea(sprite, elemParent)
{
    _color = color.darker(130);

    _path.moveTo(0, 6);
    _path.lineTo(6, 0);
    _path.lineTo(18, 0);
    _path.lineTo(24,6);
    _path.lineTo(18, 12);
    _path.lineTo(6, 12);
    _path.lineTo(0, 6);
    setFixedSize(24, 12);
}

bool DockWidget::dock(DraggableElement* elem)
{
    if(elem->getType() != DraggableElement::Predicate)
        return false;

    // init docked element
    _dockedElem = elem;
    _dockedElem->setCurrentDock(this);
    _dockedElem->setParent(_parent);
    // remove dock
    int index = _parent->getParamLayout()->indexOf(this);
    _parent->getParamLayout()->removeWidget(this);
    // insert docked element
    _parent->getParamLayout()->insertWidget(index, _dockedElem);
    hide();

    deactivate();
    if(elem->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());

    return true;
}

void DockWidget::undock()
{
    // remove docked element
    int index = _parent->getParamLayout()->indexOf(_dockedElem);
    _parent->getParamLayout()->removeWidget(_dockedElem);
    QPoint pos = _dockedElem->mapToGlobal(QPoint(0, 0));
    // reset docked element
    _dockedElem->setCurrentDock(0);
    _dockedElem->setParent(sMainWindow);
    _dockedElem->move(pos);
    _dockedElem->show();
    _dockedElem = 0;
    // insert dock
    _parent->getParamLayout()->insertWidget(index, this);
    show();

    activate();
    if(_parent->getRoot()->getType() == DraggableElement::Hat)
        sMainWindow->reloadCodeSprite(getSprite());
}

DockWidget::~DockWidget()
{
}

void DockWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // style(), width(), brush(), capStyle() and joinStyle().
    QPen pen(QColor(_color), 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(pen);

    // Brush
    QBrush brush;
    brush.setColor(QColor(_color));
    brush.setStyle(Qt::SolidPattern);

    // Draw polygon
    painter.fillPath(_path, brush);
    painter.setBackgroundMode(Qt::TransparentMode);
    setRect(QRect(mapToGlobal(QPoint(0, 0)), QSize(24, 12)));
}

QString DockWidget::getDockedElemIdent() const
{
    // TODO
    if(_dockedElem) return _dockedElem->getIdentifier();
    return "None";
}

ParamDock::ParamDock(QColor color, Sprite *sprite, DraggableElement *elemParent, QWidget *parent)
    : _dockWidget(new DockWidget(color, sprite, elemParent, parent))
{
}

ParamDock::~ParamDock()
{
    if(_dockWidget->getDockedElem()) _dockWidget->getDockedElem()->removeChildDragElems();
}

QString ParamDock::getValue() const
{
    return _dockWidget->getDockedElemIdent();
}

