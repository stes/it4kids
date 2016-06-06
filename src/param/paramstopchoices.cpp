#include "paramstopchoices.h"

ParamStopChoices::ParamStopChoices(QWidget *parent) : QComboBox(parent)
{
    addItem("all");
    addItem("this Script");
    addItem("this Block");
    addItem("all but this Script");
    addItem("other Scripts in Sprite");
}

QString ParamStopChoices::getValue()
{
    return addQuotes(currentText());
}

ParamStopChoices::~ParamStopChoices()
{

}


