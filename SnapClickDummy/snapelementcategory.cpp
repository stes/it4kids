#include "snapelementcategory.h"

SnapElementCategory::SnapElementCategory(const QString &text, const QString &color, QWidget *parent) :
    QPushButton(text, parent), _active(false), _color(color)
{
    setObjectName(text);
    setFixedSize(81, 18);
    setStyleSheet("SnapElementCategory#" + text + "{background: qlineargradient( x1:0 y1:0, x2:1 y2:0,"
                  "     stop:0 "+ color + ", stop:0.2 #373737);"
                  "     border: none; border-radius: 9px; color: #ffffff;"
                  "     padding-left: 10px; padding-top: -2px;"
                  "     text-align: center; font-size: 10px; font-weight: bold;}"
                  "SnapElementCategory:hover#" + text + " {background-color:" + color + "}");
    connect(this, SIGNAL(clicked()), this, SLOT(ToggleActive()));
}

SnapElementCategory::~SnapElementCategory()
{

}

void SnapElementCategory::ToggleActive()
{
    if(!_active)
    {
        setStyleSheet("SnapElementCategory#" + QAbstractButton::text() + "{background-color:" + _color +";"
                      "     border: none; border-radius: 9px; color: #ffffff;"
                      "     padding-left: 10px; padding-top: -2px;"
                      "     text-align: center; font-size: 10px; font-weight: bold;}");
        _active = true;
        emit CategoryChange(this);
    } else
    {
        setStyleSheet("SnapElementCategory#" + QAbstractButton::text() + "{background: qlineargradient( x1:0 y1:0, x2:1 y2:0,"
                          "     stop:0 "+ _color + ", stop:0.2 #373737);"
                          "     border: none; border-radius: 9px; color: #ffffff;"
                          "     padding-left: 10px; padding-top: -2px;"
                          "     text-align: center; font-size: 10px; font-weight: bold;}");
        _active = false;
    }
}
