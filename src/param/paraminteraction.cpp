#include <QComboBox>

#include "paraminteraction.h"

ParamInteraction::ParamInteraction(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("clicked");
    _comboBox->addItem("dragged");
    _comboBox->addItem("dropped");
    _comboBox->addItem("hover");
}
ParamInteraction::~ParamInteraction()
{

}
