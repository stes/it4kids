#include "dragableelement.h"

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

DragableElement::DragableElement(const QString& identifier, const QString& text, const QColor& color, Type type, Sprite* sprite, QWidget* parent) :
    QWidget(parent), _color(color), _text(text), _identifier(identifier), _static(false),
    _width(0), _height(0), _sprite(sprite), _path(QPoint(0, 0)),
    _type(type), _currentDock(0), _prevElem(0), _nextElem(0)
{
    _layout.setSpacing(5);
    setLayout(&_layout);
    hide();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequested(QPoint)));
    connect(this, SIGNAL(dragElemContextMenuRequested(QPoint,DragableElement*)), sMainWindow, SLOT(dragElemContextMenuRequested(QPoint,DragableElement*)));

    if(_sprite)
        _sprite->addElement(this);
}

DragableElement *DragableElement::copyParams(DragableElement *dst)
{
    for(uint i = 0; i < dst->_paramsVector.size(); i++)
    {
        dst->_paramsVector[i]->setValue(_paramsVector[i]->getValue());
    }
    return dst;
}

DragableElement *DragableElement::getRoot()
{
    DragableElement *root = this;
    while(root->_prevElem)
        root = root->_prevElem;
    return root;
}

void DragableElement::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        _offset = event->pos();
        if(_static)
        {
            DragableElement* element = getCurrentElement(sMainWindow->getCurrentSprite(), sMainWindow);
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

void DragableElement::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(mapToParent(event->pos() - _offset));
        rearrangeLowerElems();
        if(!isVisible()) show();
        update();
    }
}

void DragableElement::mouseReleaseEvent(QMouseEvent* event)
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

void DragableElement::paintEvent(QPaintEvent*)
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

void DragableElement::getLayoutSize()
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

void DragableElement::parseText(const QString &text, DragableElement *element)
{
    QStringList stringList = text.split(" ", QString::SkipEmptyParts);
    for(int i = 0; i < stringList.size(); i++)
    {
        QString str = stringList.at(i);

        if(str.contains("%Pixmap"))
        {
            QString pixmapPath = str;
            pixmapPath.remove(0, 7);
            QLabel* pixmap = new QLabel(element);
            QPixmap image(pixmapPath);
            pixmap->setPixmap(image.scaled(15, 15, Qt::KeepAspectRatio));
            pixmap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            pixmap->setStyleSheet("background-color: none;");
            element->_layout.addWidget(pixmap);
        }
        else if(str.contains("%dir"))
        {
            ParamDirection* selecBox = new ParamDirection(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%dst"))
        {
            ParamDestination* selecBox = new ParamDestination(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%key"))
        {
            ParamKey* selecBox = new ParamKey(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%interaction"))
        {
            ParamInteraction* selecBox = new ParamInteraction(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%msg"))
        {
            ParamMessage* selecBox = new ParamMessage(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%stopChoices"))
        {
            ParamStopChoices* selecBox = new ParamStopChoices(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%cln"))
        {
            ParamClone* selecBox = new ParamClone(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%cst"))
        {
            ParamCostume* selecBox = new ParamCostume(element, element->_sprite);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%eff"))
        {
            ParamEffect* selecBox = new ParamEffect(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%col"))
        {
            ParamTouch* selecBox = new ParamTouch(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%clr"))
        {
            ParamColor* selecBox = new ParamColor(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%snd"))
        {
            ParamSound* selecBox = new ParamSound(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%fun"))
        {
            ParamMath* selecBox = new ParamMath(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%words"))
        {
            ParamJoinWords* selecBox = new ParamJoinWords(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%typ"))
        {
            ParamType* selecBox = new ParamType(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%delim"))
        {
            ParamDelim* selecBox = new ParamDelim(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%var"))
        {
            ParamVariables* selecBox = new ParamVariables(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(str.contains("%idx"))
        {
            ParamListId* tE = new ParamListId(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(str.contains("%n"))
        {
            ParamNumber* tE = new ParamNumber(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(str.contains("%s"))
        {
            ParamString* tE = new ParamString(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(str.contains("%l"))
        {
            ParamListSelec* tE = new ParamListSelec(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(str.contains("%b"))
        {
            ParamDock* dock = new ParamDock(element->_color, element->_sprite, element);
            element->_layout.addWidget(dock);
            element->_paramsVector.push_back(dock);
        }
        else
        {
            QLabel* text = new QLabel(str, element);
            text->setFont(QFont("Helvetica", -1, QFont::Bold));
            element->_layout.addWidget(text);
        }
    }
}

void DragableElement::contextMenuRequested(const QPoint &pos)
{
    emit dragElemContextMenuRequested(pos, this);
}

DragableElement::~DragableElement()
{
    if(_sprite)
        _sprite->removeElement(this);
}
