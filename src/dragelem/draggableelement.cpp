#include "draggableelement.h"

#include "mainwindow.h"
#include "param/param.h"
#include "param/paramcolor.h"
#include "param/paramclone.h"
#include "param/paramcostume.h"
#include "param/paramdelim.h"
#include "param/paramdestination.h"
#include "param/paramdirection.h"
#include "param/paramdock.h"
#include "param/parameffect.h"
#include "param/paraminteraction.h"
#include "param/paramjoinwords.h"
#include "param/paramkey.h"
#include "param/paramlistid.h"
#include "param/paramlistselec.h"
#include "param/parammath.h"
#include "param/parammessage.h"
#include "param/paramnumber.h"
#include "param/paramsound.h"
#include "param/paramstopchoices.h"
#include "param/paramstring.h"
#include "param/paramtouch.h"
#include "param/paramtype.h"
#include "param/paramvariables.h"

extern MainWindow* sMainWindow;

DraggableElement::DraggableElement(const QString& identifier, const QString& text, const QColor& color, Type type, Sprite* sprite, QWidget* parent) :
    QWidget(parent), _color(color), _text(text), _identifier(identifier), _static(false),
    _width(0), _height(0), _sprite(sprite), _path(QPoint(0, 0)),
    _type(type), _currentDock(0), _prevElem(0), _nextElem(0)
{
    _layout.setSpacing(5);
    setLayout(&_layout);
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
    while(root->_prevElem)
        root = root->_prevElem;
    return root;
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
                 sMainWindow->reloadCode();
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
        update();
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
            removeChildDragElems();
            if(reload)
                sMainWindow->reloadCode();
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

void DraggableElement::getLayoutSize()
{
    _width = 0;
    _height = 0;
    for(int i = 0; i < _layout.count(); i++)
    {
        _width += _layout.itemAt(i)->widget()->width() + 5;
        _height = _layout.itemAt(i)->widget()->height() > _height ? _layout.itemAt(i)->widget()->height() : _height;
    }
    _layout.setSizeConstraint(QLayout::SetNoConstraint);
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
            _layout.addWidget(pixmap);
        }
        else if(str.contains(QLatin1String("%dir")))
        {
            ParamDirection* selecBox = new ParamDirection(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%dst")))
        {
            ParamDestination* selecBox = new ParamDestination(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%key")))
        {
            ParamKey* selecBox = new ParamKey(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%interaction")))
        {
            ParamInteraction* selecBox = new ParamInteraction(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%msg")))
        {
            ParamMessage* selecBox = new ParamMessage(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%stopChoices")))
        {
            ParamStopChoices* selecBox = new ParamStopChoices(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%cln")))
        {
            ParamClone* selecBox = new ParamClone(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%cst")))
        {
            ParamCostume* selecBox = new ParamCostume(this, _sprite);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%eff")))
        {
            ParamEffect* selecBox = new ParamEffect(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%col")))
        {
            ParamTouch* selecBox = new ParamTouch(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%clr")))
        {
            ParamColor* selecBox = new ParamColor(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%snd")))
        {
            ParamSound* selecBox = new ParamSound(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%fun")))
        {
            ParamMath* selecBox = new ParamMath(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%words")))
        {
            ParamJoinWords* selecBox = new ParamJoinWords(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%typ")))
        {
            ParamType* selecBox = new ParamType(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%delim")))
        {
            ParamDelim* selecBox = new ParamDelim(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%var")))
        {
            ParamVariables* selecBox = new ParamVariables(this);
            _layout.addWidget(selecBox);
            _paramsVector.push_back(selecBox);
        }
        else if(str.contains(QLatin1String("%idx")))
        {
            ParamListId* tE = new ParamListId(this);
            _layout.addWidget(tE);
            _paramsVector.push_back(tE);
        }
        else if(str.contains(QLatin1String("%n")))
        {
            ParamNumber* tE = new ParamNumber(this);
            _layout.addWidget(tE);
            _paramsVector.push_back(tE);
        }
        else if(str.contains(QLatin1String("%s")))
        {
            ParamString* tE = new ParamString(this);
            _layout.addWidget(tE);
            _paramsVector.push_back(tE);
        }
        else if(str.contains(QLatin1String("%l")))
        {
            ParamListSelec* tE = new ParamListSelec(this);
            _layout.addWidget(tE);
            _paramsVector.push_back(tE);
        }
        else if(str.contains(QLatin1String("%b")))
        {
            ParamDock* dock = new ParamDock(_color, _sprite, this);
            _layout.addWidget(dock);
            _paramsVector.push_back(dock);
        }
        else
        {
            QLabel* text = new QLabel(str, this);
            text->setFont(QFont("Helvetica", -1, QFont::Bold));
            _layout.addWidget(text);
        }
    }
}

void DraggableElement::contextMenuRequested(const QPoint &pos)
{
    emit dragElemContextMenuRequested(pos, this);
}

DraggableElement::~DraggableElement()
{
    if(_sprite)
        _sprite->removeElement(this);
}
