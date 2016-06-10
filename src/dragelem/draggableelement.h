#ifndef DRAGABLEELEMENT_H
#define DRAGABLEELEMENT_H

#include <vector>

#include <QWidget>
#include <QColor>
#include <QString>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QApplication>
#include <QDebug>

#include "scriptdock.h"
#include "sprite.h"

class DockingArea;
struct ArgumentStruct;
class ParamBase;

class DraggableElement : public QWidget
{
    Q_OBJECT
public:
    enum Type
    {
        Hat,
        Command,
        Wrapper,
        Predicate,
        Reporter
    };

    DraggableElement(const QString& identifier, const QString& text, const QColor& color, Type type, Sprite* sprite = 0, QWidget* parent = 0);
    virtual ~DraggableElement();

    inline void setCurrentDock(DockingArea* dock) {_currentDock = dock;}
    //inline DockingArea* getDockElem() {return _currentDock;}
    inline void setPrevElem(DraggableElement* elem) {_prevElem = elem;}
    inline DraggableElement* getPrevElem() {return _prevElem;}
    inline void setNextElem(DraggableElement* elem) {_nextElem = elem;}
    inline DraggableElement* getNextElem() {return _nextElem;}
    inline QString getIdentifier() {return _identifier;}
    inline std::vector<ParamBase*>* getParamsVector() {return &_paramsVector; }

    virtual inline int getHeight() const {return _height;}
    virtual inline int getWidth()const  {return _width;}
    bool isStatic() const { return _static; }
    void makeStatic() { _static = true; }

    virtual void resize() = 0;
    virtual DraggableElement* getWrapElem(){return (DraggableElement*)0;}

    virtual void rearrangeLowerElems() { };
    virtual void rearrangeUpperElems() { };

    virtual QPoint getLowerOffsett() const { return LOWEROFFSET; }
    virtual QPoint getUpperOffsett() const { return UPPEROFFSET; }

    virtual void removeChildDragElems() = 0;

    Type getType() const { return _type; }
    virtual DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent) = 0;

    DraggableElement *copyParams(DraggableElement *dst);

    DraggableElement *getRoot();

    virtual ScriptDock *getDock(ScriptDock::Type) { return 0; }

signals:
    void dragElemContextMenuRequested(const QPoint& pos, DraggableElement* elem);
public slots:
    void contextMenuRequested(const QPoint& pos);

protected:
    QColor _color;
    QString _text;
    QString _identifier;
    QPoint _offset;
    bool _static;
    int _width;
    int _height;

    Sprite* _sprite;

    QPainterPath _path;
    Type _type;

    QHBoxLayout _layout;

    std::vector<ParamBase*> _paramsVector;

    DockingArea* _currentDock;
    DraggableElement* _prevElem;
    DraggableElement* _nextElem;

    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);

    virtual void paintEvent(QPaintEvent*);

    void getLayoutSize();

    void parseText(const QString& text);
};

#endif // DRAGABLEELEMENT_H
