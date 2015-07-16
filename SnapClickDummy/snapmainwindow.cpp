#include "snapmainwindow.h"
#include <QDebug>

SnapMainWindow::SnapMainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);

    QFile styleSheet(":/snap/Resources/style.qss");
    styleSheet.open(QFile::ReadOnly);
    QString _styleSheet = QLatin1String(styleSheet.readAll());
    setStyleSheet(_styleSheet);

    _toolBar = new SnapToolBar(this);
    addToolBar(Qt::TopToolBarArea ,_toolBar);

    _centralWidget = new QWidget();
    _centralLayout = new QHBoxLayout();

    _snapElementList = new SnapElementWidget(this);
    _centralLayout->addWidget(_snapElementList);

    _centerArea = new CenterArea(this);
    _centralLayout->addWidget(_centerArea);

    _rightTab = new QLabel();
    _rightTab->setObjectName("rightTab");
    _rightTab->setFixedWidth(481);
    _rightTab->setStyleSheet("QLabel#rightTab {border-top: 4px solid #272727; border-left: 2px solid #272727}");
    _centralLayout->addWidget(_rightTab);

    _rightLayout = new QVBoxLayout();

    _stageBar1 = new QLabel();
    _stageBar1->setObjectName("stageBar");
    _stageBar1->setMinimumSize(QSize(481, 30));
    _stageBar1->setStyleSheet("QLabel#stageBar {background-color: #373737; border: none;}");

    QHBoxLayout* stageBarLayout = new QHBoxLayout();
    stageBarLayout->setContentsMargins(0, 0, 0, 0);
    _stageBar1->setLayout(stageBarLayout);
    _stageBar1->setAlignment(Qt::AlignLeft);

    _maximizeStage = new SnapRoundButton(":/snap/Resources/maximizestageicon.png");
    stageBarLayout->addWidget(_maximizeStage);
    _fullScreenStage = new SnapRoundButton(":/snap/Resources/fullscreenstageicon.png");
    stageBarLayout->addWidget(_fullScreenStage);

    _spacer = new QSpacerItem(0,0, QSizePolicy::Expanding);
    stageBarLayout->addItem(_spacer);

    _startScript = new SnapRoundButton(":/snap/Resources/startscripticon.png");
    stageBarLayout->addWidget(_startScript);
    _pauseScript = new SnapRoundButton(":/snap/Resources/pausescripticon.png");
    stageBarLayout->addWidget(_pauseScript);
    _stopScript = new SnapRoundButton(":/snap/Resources/stopscripticon.png");
    stageBarLayout->addWidget(_stopScript);

    _rightLayout->addWidget(_stageBar1);

    _stage = new QLabel();
    _stage->setObjectName("stage");
    _stage->setFixedSize(QSize(481, 360));
    _stage->setStyleSheet("QLabel#stage {background-color: #ffffff; border-bottom: 4px solid #272727;}");
    _rightLayout->addWidget(_stage);

    _stageBar2 = new QLabel();
    _stageBar2->setObjectName("stageBar");
    _stageBar2->setMinimumSize(QSize(481, 30));
    _rightLayout->addWidget(_stageBar2);

    _spriteList = new QLabel();
    _spriteList->setObjectName("spriteList");
    _spriteList->setFixedWidth(481);
    _spriteList->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    _spriteList->setStyleSheet("QLabel#spriteList {background-color: #474747; border: none;}");
    _rightLayout->addWidget(_spriteList);

    _rightLayout->setContentsMargins(0, 0, 0, 0);
    _rightLayout->setSpacing(0);
    _rightLayout->setAlignment(Qt::AlignTop);
    _rightTab->setLayout(_rightLayout);

    _centralLayout->setContentsMargins(0, 0, 0, 0);
    _centralLayout->setSpacing(0);
    _centralWidget->setLayout(_centralLayout);

    setCentralWidget(_centralWidget);
    showMaximized();
}

SnapMainWindow::~SnapMainWindow()
{

}
