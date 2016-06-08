#include "paramstopchoices.h"

ParamStopChoices::ParamStopChoices(QWidget *parent) : QComboBox(parent)
{
    addItem("all");
    addItem("this Script");
    addItem("this Block");
    addItem("all but this Script");
    addItem("other Scripts in Sprite");
}

QString ParamStopChoices::getString() const
{
    return currentText();
}

ParamStopChoices::~ParamStopChoices()
{

}


