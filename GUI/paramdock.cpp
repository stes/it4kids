#include "paramdock.h"
#include "predicatede.h"
//#include "qDebug.h"

ParamDock::ParamDock(QColor color, ScriptArea* scriptAreaWidget, QWidget *parent) : QWidget(parent),
    _dockedElem(0), _scriptArea(scriptAreaWidget)
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
}

void ParamDock::dock(DragableElement* dragElem)
{
    _dockedElem = dragElem;
    parentWidget()->layout()->addWidget(_dockedElem);
    parentWidget()->layout()->removeWidget(this);
    _dockedElem->setParent(parentWidget());
    _dockedElem->show();
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

QString ParamDock::getValue()
{
    return QString("ParamDock");
}

ParamDock::~ParamDock()
{
    _scriptArea->removeFromHitTest(this);
}

void ParamDock::paintEvent(QPaintEvent*)
{
    if(!_dockedElem)
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
    }
}
