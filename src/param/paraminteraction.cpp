#include "paraminteraction.h"

ParamInteraction::ParamInteraction(QWidget *parent) : QComboBox(parent)
{
    addItem("clicked");
    addItem("dragged");
    addItem("dropped");
    addItem("hover");
}

QString ParamInteraction::getValue()
{
    return addQuotes(currentText());
}

ParamInteraction::~ParamInteraction()
{

}
