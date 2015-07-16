#ifndef SNAPTOOLBAR
#define SNAPTOOLBAR

#include <QToolBar>
#include <QLabel>

#include "snaproundbutton.h"

class SnapToolBar : public QToolBar
{
    Q_OBJECT

public:
    SnapToolBar(QWidget* parent = 0),
    ~SnapToolBar();

protected:
    QLabel* _toolBarLogo;

    SnapRoundButton* _buttonFile;
    SnapRoundButton* _buttonCloud;
    SnapRoundButton* _buttonOptions;

    QWidget* _toolBarSpacer;

    SnapRoundButton* _buttonMinimize;
    SnapRoundButton* _buttonMaximize;
    SnapRoundButton* _buttonClose;
};

#endif // SNAPTOOLBAR

