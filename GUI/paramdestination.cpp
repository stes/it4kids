#include "paramdestination.h"

ParamDestination::ParamDestination(QWidget *parent) : QComboBox(parent)
{
    addItem("mouse");
    #warning "Add Destination list to ParamDestination"
}

QString ParamDestination::getValue()
{
    return QString("ParamDestination");
}

ParamDestination::~ParamDestination()
{

}

