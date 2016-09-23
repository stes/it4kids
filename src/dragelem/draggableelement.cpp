#include <QPainter>

#include "draggableelement.h"

#include "param/param.h"
#include "mainwindow.h"
#include "commandde.h"
#include "hatde.h"
#include "wrapperde.h"
#include "predicatede.h"
#include "reporterde.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

DraggableElement* DraggableElement::createNewElement(
        const QString& type,
        const QString& identifier,
        const QString& text,
        const QColor& color,
        Sprite* sprite,
        QWidget* parent)
{
    if(type == QLatin1String("command"))
        return new CommandDE(identifier, text, color, sprite, parent);
    if(type == QLatin1String("hat"))
        return new HatDE(identifier, text, color, sprite, parent);
    if(type == QLatin1String("wrapper"))
        return new WrapperDE(identifier, text, color, sprite, parent);
    if(type == QLatin1String("predicate"))
        return new PredicateDE(identifier, text, color, sprite, parent);
    if(type == QLatin1String("reporter"))
        return new ReporterDE(identifier, text, color, sprite, parent);
    return 0;
}

DraggableElement::DraggableElement(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite, QWidget* parent) :
    QWidget(parent),
    _color(color),
    _text(text),
    _identifier(identifier),
    _static(false),
    _sprite(sprite),
    _path(QPoint(0, 0)),
    _currentDock(0),
    _prevElem(0),
    _nextElem(0)
{
    _paramLayout = new QHBoxLayout();
    _paramLayout->setSpacing(5);
    _paramLayout->setSizeConstraint(QLayout::SetFixedSize);
    _paramLayout->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    hide();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequested(QPoint)));
    connect(this, SIGNAL(dragElemContextMenuRequested(QPoint,DraggableElement*)), sMainWindow, SLOT(dragElemContextMenuRequested(QPoint,DraggableElement*)));

    if(_sprite)
        _sprite->addElement(this);

    parseText(text);
}

DraggableElement *DraggableElement::copyParams(DraggableElement *dst)
{
    for(uint i = 0; i < dst->_paramsVector.size(); i++)
    {
        dst->_paramsVector[i]->setValue(_paramsVector[i]->getValue());
    }
    return dst;
}

DraggableElement *DraggableElement::getRoot()
{
    DraggableElement *root = this;
    while(root->_currentDock && root->_currentDock->getParent())
        root = root->_currentDock->getParent();
    return root;
}

DraggableElement *DraggableElement::getOuter()
{
    DraggableElement *out = this;
    while(out->_prevElem)
    {
        if(out->_prevElem->_nextElem != out)
            return out->_prevElem;
        out = out->_prevElem;
    }
    return 0;
}

void DraggableElement::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        _offset = event->pos();
        if(_static)
        {
            DraggableElement* element = getCurrentElement(sMainWindow->getCurrentSprite(), sMainWindow);
            element->update();
            element->grabMouse();
            if(element->getType() == Hat)
                 sMainWindow->reloadCodeSprite(element->_sprite);
        }
        else
        {
            if(_currentDock)
                _currentDock->undock();
            grabMouse();
            raise();
        }
    }
}

void DraggableElement::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(mapToParent(event->pos() - _offset));
        rearrangeLowerElems();
        if(!isVisible()) show();
    }
}

void DraggableElement::mouseReleaseEvent(QMouseEvent* event)
{
    releaseMouse();
    if(event->button() == Qt::LeftButton)
    {
        QRect scriptArea = sMainWindow->getScriptAreaRect();
        if(!scriptArea.contains(QRect(mapToGlobal(QPoint(0, 0)), QSize(width(), height())), true))
        {
            bool reload = getType() == Hat;
            Sprite *sprite = _sprite;
            removeChildDragElems();
            if(reload)
                sMainWindow->reloadCodeSprite(sprite);
        }
        else
            _sprite->performHitTest(this);
    }
}

void DraggableElement::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // style(), width(), brush(), capStyle() and joinStyle().
    QPen pen(_color, 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(pen);

    // Brush
    QBrush brush;
    brush.setColor(_color);
    brush.setStyle(Qt::SolidPattern);

    // Draw polygon
    painter.fillPath(_path, brush);
    painter.setBackgroundMode(Qt::TransparentMode);
}

void DraggableElement::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    updateDocks();
    rearrangeLowerElems();
    DraggableElement *outer = getOuter();
    if(outer)
        outer->updateSize();
}

void DraggableElement::parseText(const QString &text)
{
    QStringList stringList = text.split(' ', QString::SkipEmptyParts);
    for(int i = 0; i < stringList.size(); i++)
    {
        QString str = stringList.at(i);

        if(str.contains(QLatin1String("%Pixmap")))
        {
            QString pixmapPath = str;
            pixmapPath.remove(0, 7);
            QLabel* pixmap = new QLabel(this);
            QPixmap image(pixmapPath);
            pixmap->setPixmap(image.scaled(15, 15, Qt::KeepAspectRatio));
            pixmap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            pixmap->setStyleSheet("background-color: none;");
            _paramLayout->addWidget(pixmap);
            continue;
        }

        ParamBase *param = ParamBase::createParam(str, this, _sprite, this, _color);

        if(param)
        {
            _paramLayout->addWidget(param->getWidget());
            _paramsVector.push_back(param);
        }
        else
        {
            QLabel* text = new QLabel(str, this);
            text->setFont(QFont("Helvetica", -1, QFont::Bold));
            _paramLayout->addWidget(text);
        }
    }
}

void DraggableElement::contextMenuRequested(const QPoint &pos)
{
    emit dragElemContextMenuRequested(pos, this);
}

DraggableElement::~DraggableElement()
{
    while (!_paramsVector.empty())
    {
        delete _paramsVector.back();
        _paramsVector.pop_back();
    }

    if(_sprite)
        _sprite->removeElement(this);
}
