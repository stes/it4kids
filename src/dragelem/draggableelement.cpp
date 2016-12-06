#include <QMenu>
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
    // TODO: bigger border
    QPen pen(_color.darker(120), 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    QBrush brush(_color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPath(_path);
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

void DraggableElement::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu myMenu(this);
    if(!isStatic())
    {
        myMenu.addAction(tr("duplicate"));
        myMenu.addAction(tr("delete"));
        myMenu.addAction(tr("add comment"));
        myMenu.addAction(tr("help"));
    }
    else
    {
        myMenu.addAction(tr("help"));
    }
    myMenu.exec(event->globalPos());
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
            _paramLayout->addWidget(pixmap);
            continue;
        }

        ParamBase *param = ParamBase::createParam(str, this, _sprite, this, _color);

        if(param)
        {
            param->getWidget()->setStyleSheet(QString("border-color: %1").arg(_color.darker(120).name()));
            _paramLayout->addWidget(param->getWidget());
            _paramsVector.push_back(param);
        }
        else
        {
            QLabel* text = new QLabel(str, this);
            _paramLayout->addWidget(text);
        }
    }
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
