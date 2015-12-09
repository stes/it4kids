#include "paraminteraction.h"

ParamInteraction::ParamInteraction(QWidget *parent) : QComboBox(parent)
{
    addItem("clicked");
    addItem("dragged");
    addItem("dropped");
    addItem("hover");
    #pragma message("Fix GetValue")
}

QString ParamInteraction::getValue()
{
    return QString("ParamInteraction");
}

ParamInteraction::~ParamInteraction()
{

}
