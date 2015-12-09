#include "paramdock.h"
#include "predicatede.h"
#include "qDebug.h"

ParamDock::ParamDock(QColor color, ScriptArea* scriptAreaWidget, QWidget *parent) : QWidget(parent),
    DockingArea(), _scriptArea(scriptAreaWidget)
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

    _scriptArea->addToHitTest(this);

    #pragma message("Fix GetValue")
}

void ParamDock::dock(DragableElement* dragElem)
{
    QString elemClass(dragElem->metaObject()->className());
    if(elemClass == "PredicateDE")
    {
        _dockedElem = dragElem;
        _dockedElem->setCurrentDock(this);
        int index = ((QBoxLayout*) (parentWidget()->layout()))->indexOf(this);
        ((QBoxLayout*) (parentWidget()->layout()))->removeWidget(this);
        ((QBoxLayout*) (parentWidget()->layout()))->insertWidget(index, _dockedElem);
        _dockedElem->setParent(parentWidget());
        _dockedElem->show();
        hide();
        QString className(parentWidget()->metaObject()->className());
        if(className == "QWidget")
        {
            ((DragableElement*) parentWidget()->parentWidget())->resize();
            ((DragableElement*) parentWidget()->parentWidget())->show();
        }
        else
        {
            ((DragableElement*) parentWidget())->resize();
            ((DragableElement*) parentWidget())->show();
        }
    }
}

void ParamDock::undock()
{
    int index = ((QBoxLayout*) (parentWidget()->layout()))->indexOf(_dockedElem);
    ((QBoxLayout*) (parentWidget()->layout()))->removeWidget(_dockedElem);
    QPoint pos = _dockedElem->mapToGlobal(_dockedElem->pos());
    _dockedElem->setParent(QApplication::activeWindow());
    _dockedElem->move(_dockedElem->mapFromGlobal(pos));
    _dockedElem->show();
    ((QBoxLayout*) (parentWidget()->layout()))->insertWidget(index, this);
    show();
    QString className(parentWidget()->metaObject()->className());
    if(className == "QWidget")
    {
        ((DragableElement*) parentWidget()->parentWidget())->resize();
        ((DragableElement*) parentWidget()->parentWidget())->resize();
        ((DragableElement*) parentWidget()->parentWidget())->show();
    }
    else
    {
        ((DragableElement*) parentWidget())->resize();
        ((DragableElement*) parentWidget())->resize();
        ((DragableElement*) parentWidget())->show();
    }
}

QString ParamDock::getValue()
{
    return QString("ParamDock");
}

ParamDock::~ParamDock()
{

}

void ParamDock::paintEvent(QPaintEvent*)
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
