#include "paraminteraction.h"

ParamInteraction::ParamInteraction(QWidget *parent) : QComboBox(parent)
{
    addItem("clicked");
    addItem("dragged");
    addItem("dropped");
    addItem("hover");
}

bool ParamInteraction::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamInteraction::getString() const
{
    return currentText();
}

ParamInteraction::~ParamInteraction()
{

}
