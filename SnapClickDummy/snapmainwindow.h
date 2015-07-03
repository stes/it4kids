#ifndef SNAPMAINWINDOW
#define SNAPMAINWINDOW

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QLabel>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QStyle>
#include <QGraphicsDropShadowEffect>

#include "snapelementwidget.h"
#include "centerarea.h"

class SnapMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SnapMainWindow(QWidget *parent = 0);
    ~SnapMainWindow();

private:
    QToolBar* _toolBar;
    QAction* _actionFile;
    QAction* _actionCloud;
    QAction* _actionOptions;
    QAction* _actionMinimize;
    QAction* _actionMaximize;
    QAction* _actionClose;
    QWidget* _toolBarSpacer;
    QLabel* _toolBarLogo;

    QWidget* _centralWidget;
    QHBoxLayout* _centralLayout;

    QLabel* _leftTab;
    QHBoxLayout* _leftLayout;
    SnapElementWidget* _snapElementList;
    CenterArea* _centerArea;

    QLabel* _rightTab;
    QVBoxLayout* _rightLayout;
    QLabel* _stage;
    QLabel* _stageBar1;
    QLabel* _stageBar2;
    QLabel* _spriteList;
};

#endif // SNAPMAINWINDOW

