#ifndef DRAGABLEELEMENT_H
#define DRAGABLEELEMENT_H

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

#include "scriptarea.h"
#include "scriptdock.h"

#include <vector>

#include <QDebug>

class DockingArea;

class DragableElement : public QWidget
{
    friend class MainWindow;

    Q_OBJECT
public:
    DragableElement(const QString& text, const QColor& color, const QString& type, ScriptArea* scriptAreaWidget = 0, QWidget* parent = 0);
    ~DragableElement();

    inline virtual void setScriptAreaWidget(ScriptArea *scriptAreaWidget) {_scriptAreaWidget = scriptAreaWidget;}

    inline virtual void setCurrentDock(DockingArea* dock) {_currentDock = dock;}
    virtual void setPrevElem(DragableElement* elem);
    virtual void setNextElem(DragableElement* elem);

    virtual void resize() = 0;
protected:
    QColor _color;
    QString _text;
    QPoint _offset;
    bool _dragged;
    int _width;
    int _height;

    ScriptArea* _scriptAreaWidget;

    QPainterPath _path;
    QString _type;

    QHBoxLayout _layout;

    std::vector<QString> _defaultValues;

    DockingArea* _currentDock;
    ScriptDock* _upperDock;
    ScriptDock* _lowerDock;
    DragableElement* _prevElem;
    DragableElement* _nextElem;

    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);

    virtual void paintEvent(QPaintEvent*);

    virtual DragableElement* getCurrentElement(QWidget* parent) = 0;

    void getLayoutSize();

    static void parseText(const QString& text, DragableElement* element);
};

#endif // DRAGABLEELEMENT_H
