#include "snaptoolbar.h"

SnapToolBar::SnapToolBar(QWidget *parent) :
    QToolBar(parent)
{
    _toolBarLogo = new QLabel();
    _toolBarLogo->setPixmap(QPixmap(":/snap/Resources/logo.png"));
    _toolBarLogo->setFixedSize(QSize(125, 27));

    _buttonFile = new SnapRoundButton(":/snap/Resources/fileicon.png", this);
    _buttonCloud = new SnapRoundButton(":/snap/Resources/cloudicon.png", this);
    _buttonOptions = new SnapRoundButton(":/snap/Resources/optionsicon.png", this);

    _toolBarSpacer = new QWidget();
    _toolBarSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _buttonMinimize = new SnapRoundButton(":/snap/Resources/minimizeicon.png", this);
    _buttonMaximize = new SnapRoundButton(":/snap/Resources/maximizeicon.png", this);
    _buttonClose = new SnapRoundButton(":/snap/Resources/closeicon.png", this);

    addWidget(_toolBarLogo);
    addWidget(_buttonFile);
    addWidget(_buttonCloud);
    addWidget(_buttonOptions);
    addWidget(_toolBarSpacer);
    addWidget(_buttonMinimize);
    addWidget(_buttonMaximize);
    addWidget(_buttonClose);
    setMovable(false);
    setFloatable(false);
}

SnapToolBar::~SnapToolBar()
{

}
