#include "scriptarea.h"

ScriptArea::ScriptArea(QWidget *parent) :
    QLabel(parent)
{
    setStyleSheet("background-image: url(:/snap/Resources/backgroundSnap.png);");
    setMinimumSize(200, 200);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

ScriptArea::~ScriptArea()
{

}
