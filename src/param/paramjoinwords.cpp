#include "paramjoinwords.h"

JoinWordsWidget::JoinWordsWidget(QWidget *parent) : QWidget(parent), _first(this), _second(this)
{
    _layout.addWidget(_first.getWidget());
    _layout.addWidget(_second.getWidget());
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.setSpacing(5);
    setLayout(&_layout);
    // TODO: Fix GetValue
}

JoinWordsWidget::~JoinWordsWidget()
{
}

ParamJoinWords::ParamJoinWords(QWidget *parent) : _joinWordsWidget(new JoinWordsWidget(parent))
{
}

ParamJoinWords::~ParamJoinWords()
{
}

QString ParamJoinWords::getString() const
{
    return "ParamJoinWords";
}
