#ifndef DRAGABLEELEMENT_H
#define DRAGABLEELEMENT_H

#include <vector>

#include <QWidget>
#include <QColor>
#include <QString>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainterPath>

#include "scriptdock.h"

class DockingArea;
class ParamBase;
class Sprite;

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

    static DraggableElement* createNewElement(
            const QString& type,
            const QString& identifier,
            const QString& text,
            const QColor& color,
            Sprite* sprite = 0,
            QWidget* parent = 0);

    DraggableElement(const QString& identifier, const QString& text, const QColor& color, Sprite* sprite = 0, QWidget* parent = 0);
    virtual ~DraggableElement();

    inline void setCurrentDock(DockingArea* dock) {_currentDock = dock;}
    //inline DockingArea* getDockElem() {return _currentDock;}

    inline void setPrevElem(DraggableElement* elem) {_prevElem = elem;}
    inline DraggableElement* getPrevElem() {return _prevElem;}
    inline const DraggableElement* getPrevElem() const { return _prevElem; }

    inline void setNextElem(DraggableElement* elem) {_nextElem = elem;}
    inline DraggableElement* getNextElem() {return _nextElem;}
    inline const DraggableElement* getNextElem() const { return _nextElem; }

    inline const QString &getIdentifier() const {return _identifier;}
    inline const std::vector<ParamBase*>* getParamsVector() const { return &_paramsVector; }

    bool isStatic() const { return _static; }
    void makeStatic() { _static = true; }

    virtual const DraggableElement* getWrapElem() const { return 0; }

    virtual void rearrangeLowerElems() { };
    virtual void rearrangeUpperElems() { };

    virtual void updateDocks() { };
    virtual void updateSize() { };

    virtual void removeChildDragElems() = 0;

    virtual Type getType() const = 0;
    virtual DraggableElement* getCurrentElement(Sprite *sprite, QWidget* parent) = 0;
    QHBoxLayout* getParamLayout() { return _paramLayout; }

    DraggableElement *copyParams(DraggableElement *dst);

    DraggableElement *getRoot();
    DraggableElement *getOuter();

    virtual ScriptDock *getDock(ScriptDock::Type) { return 0; }

protected:
    QColor _color;
    QString _text;
    QString _identifier;
    QPoint _offset;
    bool _static;

    Sprite* _sprite;

    QPainterPath _path;

    QHBoxLayout* _paramLayout;

    std::vector<ParamBase*> _paramsVector;

    DockingArea* _currentDock;
    DraggableElement* _prevElem;
    DraggableElement* _nextElem;

    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);

    virtual void paintEvent(QPaintEvent*);
    virtual void moveEvent(QMoveEvent*) { updateDocks(); }
    virtual void resizeEvent(QResizeEvent*);
    virtual void contextMenuEvent(QContextMenuEvent*);


    void parseText(const QString& text);
};

#endif // DRAGABLEELEMENT_H
