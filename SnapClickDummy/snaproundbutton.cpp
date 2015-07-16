#include <snaproundbutton.h>

SnapRoundButton::SnapRoundButton(const QString& iconPath, QWidget* parent) :
    QPushButton(QIcon(iconPath), "", parent)
{

}

SnapRoundButton::~SnapRoundButton()
{

}
