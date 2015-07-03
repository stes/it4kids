#include "snapmainwindow.h"

SnapMainWindow::SnapMainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    setStyleSheet("background-color: #373737; padding-top: 0px;");
    setWindowFlags(Qt::FramelessWindowHint);

    _toolBar = new QToolBar(this);

    _actionFile = new QAction(QIcon(":/snap/Resources/file.png"), "File", this);
    _actionCloud = new QAction(QIcon(":/snap/Resources/cloud.png"), "Cloud", this);
    _actionOptions = new QAction(QIcon(":/snap/Resources/options.png"), "Options", this);
    _actionMinimize = new QAction(QIcon(":/snap/Resources/minimize.png"), "Minimize", this);
    _actionMaximize = new QAction(QIcon(":/snap/Resources/maximize.png"), "Maximize", this);
    _actionClose = new QAction(QIcon(":/snap/Resources/close.png"), "Close", this);
    _toolBarSpacer = new QWidget();
    _toolBarSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _toolBarLogo = new QLabel();
    _toolBarLogo->setPixmap(QPixmap(":/snap/Resources/logo.png"));
    _toolBarLogo->setFixedSize(QSize(125, 27));

    _toolBar->addWidget(_toolBarLogo);
    _toolBar->addAction(_actionFile);
    _toolBar->addAction(_actionCloud);
    _toolBar->addAction(_actionOptions);
    _toolBar->addWidget(_toolBarSpacer);
    _toolBar->addAction(_actionMinimize);
    _toolBar->addAction(_actionMaximize);
    _toolBar->addAction(_actionClose);
    _toolBar->setMovable(false);
    _toolBar->setFloatable(false);

    addToolBar(Qt::TopToolBarArea ,_toolBar);
    _toolBar->setStyleSheet("QToolBar {background-color: #373737; border: none; }");
    _toolBar->setFixedHeight(28);
    _toolBar->setIconSize(QSize(42, 28));

    connect(_actionMinimize, SIGNAL(triggered(bool)), this, SLOT(showMinimized()));
    connect(_actionMaximize, SIGNAL(triggered(bool)), this, SLOT(showMaximized()));
    connect(_actionClose, SIGNAL(triggered(bool)), this, SLOT(close()));

    _centralWidget = new QWidget();
    _centralLayout = new QHBoxLayout();

    _leftTab = new QLabel();
    _leftTab->setObjectName("leftTab");
    _leftTab->setMinimumWidth(300);
    _leftTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _leftTab->setStyleSheet("QLabel#leftTab {border-top: 4px solid #272727; border-right: 2px solid #272727;}");

    _leftLayout = new QHBoxLayout();
    _leftLayout->setAlignment(Qt::AlignLeft);
    _leftLayout->setContentsMargins(0, 0, 0, 0);
    _leftLayout->setSpacing(0);
    _snapElementList = new SnapElementWidget(this);
    _leftLayout->addWidget(_snapElementList);
    _leftTab->setLayout(_leftLayout);
    _centralLayout->addWidget(_leftTab);

    _centerArea = new CenterArea(this);
    _leftLayout->addWidget(_centerArea);

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

    QPushButton* maximizeStage = new QPushButton(this);
    maximizeStage->setObjectName("maximizeStage");
    maximizeStage->setFixedSize(42, 24);
    maximizeStage->setStyleSheet("QPushButton#maximizeStage {background-image: url(:/snap/Resources/maximizeStage.png); border-radius: 9px;}");
    stageBarLayout->addWidget(maximizeStage);

    QPushButton* fullScreenStage = new QPushButton(this);
    fullScreenStage->setObjectName("fullScreenStage");
    fullScreenStage->setFixedSize(42, 24);
    fullScreenStage->setStyleSheet("QPushButton#fullScreenStage {background-image: url(:/snap/Resources/fullScreenStage.png); border-radius: 9px;}");
    stageBarLayout->addWidget(fullScreenStage);

    QSpacerItem* spacer = new QSpacerItem(0,0, QSizePolicy::Expanding);
    stageBarLayout->addItem(spacer);

    QPushButton* startScript = new QPushButton(this);
    startScript->setObjectName("startScript");
    startScript->setFixedSize(42, 24);
    startScript->setStyleSheet("QPushButton#startScript {background-image: url(:/snap/Resources/startScript.png); border-radius: 9px;}");
    stageBarLayout->addWidget(startScript);

    QPushButton* pauseScript = new QPushButton(this);
    pauseScript->setObjectName("pauseScript");
    pauseScript->setFixedSize(42, 24);
    pauseScript->setStyleSheet("QPushButton#pauseScript {background-image: url(:/snap/Resources/pauseScript.png); border-radius: 9px;}");
    stageBarLayout->addWidget(pauseScript);

    QPushButton* stopScript = new QPushButton(this);
    stopScript->setObjectName("stopScript");
    stopScript->setFixedSize(42, 24);
    stopScript->setStyleSheet("QPushButton#stopScript {background-image: url(:/snap/Resources/stopScript.png); border-radius: 9px;}");
    stageBarLayout->addWidget(stopScript);

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
