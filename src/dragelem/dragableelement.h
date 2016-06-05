#ifndef DRAGABLEELEMENT_H
#define DRAGABLEELEMENT_H

#include <vector>

#include <QWidget>
#include <QColor>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QApplication>
#include <QDebug>

#include "scriptarea.h"
#include "scriptdock.h"

class DockingArea;
struct ArgumentStruct;
class Param;

class DragableElement : public QWidget
{
    friend class MainWindow;
    friend class ScriptDock;
    friend class WrapperDE;

    Q_OBJECT
public:
    DragableElement(const QString& identifier, const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);

    inline virtual void setScriptAreaWidget(ScriptArea *scriptAreaWidget) {_scriptAreaWidget = scriptAreaWidget;}

    inline void setCurrentDock(DockingArea* dock) {_currentDock = dock;}
    //inline DockingArea* getDockElem() {return _currentDock;}
    inline void setPrevElem(DragableElement* elem) {_prevElem = elem;}
    inline DragableElement* getPrevElem() {return _prevElem;}
    inline void setNextElem(DragableElement* elem) {_nextElem = elem;}
    inline DragableElement* getNextElem() {return _nextElem;}
    inline QString getIdentifier() {return _identifier;}
    inline std::vector<Param*>* getParamsVector() {return &_paramsVector; }

    virtual inline int getHeight() const {return _height;}
    virtual inline int getWidth() {return _width;}
    virtual bool isDragged() {return _dragged;}

    virtual void resize() = 0;
    virtual DragableElement* getWrapElem(){return (DragableElement*)0;}

    virtual void rearrangeLowerElems() { };
    virtual void rearrangeUpperElems() { };

    virtual QPoint getLowerOffsett() const { return LOWEROFFSET; }
    virtual QPoint getUpperOffsett() const { return UPPEROFFSET; }

    virtual void removeChildDragElems() = 0;

    virtual ~DragableElement();

    QString getType() {return _type;}
    virtual DragableElement* getCurrentElement(QWidget* parent) = 0;

    DragableElement *getRoot();

signals:
    void dragElemContextMenuRequested(const QPoint& pos, DragableElement* elem);
public slots:
    void contextMenuRequested(const QPoint& pos);
protected:
    QColor _color;
    QString _text;
    QString _identifier;
    QPoint _offset;
    bool _dragged;
    int _width;
    int _height;

    ScriptArea* _scriptAreaWidget;

    QPainterPath _path;
    QString _type;

    QHBoxLayout _layout;

    std::vector<Param*> _paramsVector;

    DockingArea* _currentDock;
    DragableElement* _prevElem;
    DragableElement* _nextElem;

    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);

    virtual void paintEvent(QPaintEvent*);

    void getLayoutSize();

    void parseText(const QString& text, DragableElement* element);
};

#endif // DRAGABLEELEMENT_H
