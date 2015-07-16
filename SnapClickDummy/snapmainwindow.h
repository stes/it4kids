#ifndef SNAPMAINWINDOW
#define SNAPMAINWINDOW

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QFile>
#include <QStyle>

#include "snaptoolbar.h"

#include "snapelementwidget.h"
#include "snaproundbutton.h"
#include "centerarea.h"

class SnapMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SnapMainWindow(QWidget *parent = 0);
    ~SnapMainWindow();

private:
    QString _styleSheet;

    SnapToolBar* _toolBar;

    QWidget* _centralWidget;
    QHBoxLayout* _centralLayout;

    SnapElementWidget* _snapElementList;
    CenterArea* _centerArea;

    QLabel* _rightTab;
    QVBoxLayout* _rightLayout;

    QLabel* _stageBar1;
    SnapRoundButton* _maximizeStage;
    SnapRoundButton* _fullScreenStage;
    QSpacerItem* _spacer;
    SnapRoundButton* _startScript;
    SnapRoundButton* _pauseScript;
    SnapRoundButton* _stopScript;

    QLabel* _stage;

    QLabel* _stageBar2;
    QLabel* _spriteList;
};

#endif // SNAPMAINWINDOW

