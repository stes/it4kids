#include "paramjoinwords.h"

ParamJoinWords::ParamJoinWords(QWidget *parent) : QWidget(parent), _first(this), _second(this)
{
    _layout.addWidget(&_first);
    _layout.addWidget(&_second);
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.setSpacing(5);
    setLayout(&_layout);
    // TODO: Fix GetValue
}

QString ParamJoinWords::getString() const
{
    return "ParamJoinWords";
}

ParamJoinWords::~ParamJoinWords()
{

}


