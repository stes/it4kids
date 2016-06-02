#include "paramjoinwords.h"

#include "paramjoinwords.h"

#include <QGuiApplication>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

ParamJoinWords::ParamJoinWords(QWidget *parent) : QWidget(parent), _first(this), _second(this)
{
    _layout.addWidget(&_first);
    _layout.addWidget(&_second);
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.setSpacing(5);
    setLayout(&_layout);
    // TODO: Fix GetValue
}

QString ParamJoinWords::getValue()
{
    return QString("ParamJoinWords");
}

ParamJoinWords::~ParamJoinWords()
{

}


