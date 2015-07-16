#ifndef SNAPROUNDBUTTON
#define SNAPROUNDBUTTON

#include <QPushButton>

class SnapRoundButton : public QPushButton
{
    Q_OBJECT
public:
    SnapRoundButton(const QString& iconpath, QWidget* parent = 0);
    ~SnapRoundButton();
};

#endif // SNAPROUNDBUTTON

