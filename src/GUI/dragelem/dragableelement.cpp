#include "dragableelement.h"
#include <QDebug>

#include "mainwindow.h"
#include "param.h"
#include "paramcolor.h"
#include "paramclone.h"
#include "paramcostume.h"
#include "paramdelim.h"
#include "paramdestination.h"
#include "paramdirection.h"
#include "paramdock.h"
#include "parameffect.h"
#include "paraminteraction.h"
#include "paramjoinwords.h"
#include "paramkey.h"
#include "paramlistid.h"
#include "paramlistselec.h"
#include "parammath.h"
#include "parammessage.h"
#include "paramnumber.h"
#include "paramsound.h"
#include "paramstopchoices.h"
#include "paramstring.h"
#include "paramtouch.h"
#include "paramtype.h"
#include "paramvariables.h"

extern MainWindow* _sMainWindow;

DragableElement::DragableElement(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget, QWidget* parent) :
    QWidget(parent), _color(color), _text(text), _identifier(identifier), _dragged(false),
    _width(0), _height(0), _scriptAreaWidget(scriptAreaWidget), _path(QPoint(0, 0)),
    _type(type), _currentDock(0), _prevElem(0), _nextElem(0)
{
    _layout.setSpacing(5);
    setLayout(&_layout);
    hide();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequested(QPoint)));
    connect(this, SIGNAL(dragElemContextMenuRequested(QPoint,DragableElement*)), _sMainWindow, SLOT(dragElemContextMenuRequested(QPoint,DragableElement*)));
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
        if(!_dragged)
        {
            DragableElement* element = getCurrentElement(QApplication::activeWindow());
            for(uint i = 0; i < element->_paramsVector.size(); i++)
            {
                element->_paramsVector[i]->setValue(_paramsVector[i]->getValue());
            }
            element->update();
            element->grabMouse();
        }
        else
        {
            if(_currentDock)
                _currentDock->undock();
            grabMouse();
            resize();
            show();
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
        show();
        update();
    }
}

void DragableElement::mouseReleaseEvent(QMouseEvent* event)
{
    releaseMouse();
    if(event->button() == Qt::LeftButton)
    {
        QRect scriptArea = QRect(_scriptAreaWidget->mapToGlobal(QPoint(0,0)), QSize(_scriptAreaWidget->width(), _scriptAreaWidget->height()));
        if(!scriptArea.contains(QRect(mapToGlobal(QPoint(0, 0)), QSize(width(), height())), true))
        {
            bool reload = getType() == "hat";
            ScriptArea *scriptAreaWidget = _scriptAreaWidget;
            removeChildDragElems();
            if(reload)
                scriptAreaWidget->reloadCode();
            return;
        }
        if(!_dragged)
        {
            _scriptAreaWidget->addToDragElem(this);
            _dragged = true;
            if(getType() == "hat")
                _scriptAreaWidget->reloadCode();
        }
        _scriptAreaWidget->performHitTest(this);
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
        if(stringList.at(i).contains("%Pixmap"))
        {
            QString pixmapPath = stringList.at(i);
            pixmapPath.remove(0, 7);
            QLabel* pixmap = new QLabel(element);
            QPixmap image(pixmapPath);
            pixmap->setPixmap(image.scaled(15, 15, Qt::KeepAspectRatio));
            pixmap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            pixmap->setStyleSheet("background-color: none;");
            element->_layout.addWidget(pixmap);
        }
        else if(stringList.at(i).contains("%dir"))
        {
            ParamDirection* selecBox = new ParamDirection(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%dst"))
        {
            ParamDestination* selecBox = new ParamDestination(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%key"))
        {
            ParamKey* selecBox = new ParamKey(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%interaction"))
        {
            ParamInteraction* selecBox = new ParamInteraction(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%msg"))
        {
            ParamMessage* selecBox = new ParamMessage(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%stopChoices"))
        {
            ParamStopChoices* selecBox = new ParamStopChoices(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%cln"))
        {
            ParamClone* selecBox = new ParamClone(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%cst"))
        {
            ParamCostume* selecBox = new ParamCostume(element);
            element->_layout.addWidget(selecBox);
        }
        else if( stringList.at(i).contains("%eff"))
        {
            ParamEffect* selecBox = new ParamEffect(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%col"))
        {
            ParamTouch* selecBox = new ParamTouch(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%clr"))
        {
            ParamColor* selecBox = new ParamColor(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%snd"))
        {
            ParamSound* selecBox = new ParamSound(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%fun"))
        {
            ParamMath* selecBox = new ParamMath(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%words"))
        {
            ParamJoinWords* selecBox = new ParamJoinWords(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%typ"))
        {
            ParamType* selecBox = new ParamType(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%delim"))
        {
            ParamDelim* selecBox = new ParamDelim(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if( stringList.at(i).contains("%var"))
        {
            ParamVariables* selecBox = new ParamVariables(element);
            element->_layout.addWidget(selecBox);
            element->_paramsVector.push_back(selecBox);
        }
        else if(stringList.at(i).contains("%idx"))
        {
            ParamListId* tE = new ParamListId(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(stringList.at(i).contains("%n"))
        {
            ParamNumber* tE = new ParamNumber(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(stringList.at(i).contains("%s"))
        {
            ParamString* tE = new ParamString(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(stringList.at(i).contains("%l"))
        {
            ParamListSelec* tE = new ParamListSelec(element);
            element->_layout.addWidget(tE);
            element->_paramsVector.push_back(tE);
        }
        else if(stringList.at(i).contains("%b"))
        {
             ParamDock* dock = new ParamDock(element->_color, element->_scriptAreaWidget, element);
             element->_layout.addWidget(dock);
             element->_paramsVector.push_back(dock);
        }
        else
        {
            QLabel* text = new QLabel(stringList.at(i), element);
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

}
