#include "parammessage.h"

ParamMessage::ParamMessage(QWidget *parent) : QComboBox(parent)
{
    addItem("message1");
    #warning "Add Message list to ParamMessage"
}

QString ParamMessage::getValue()
{
    return QString("ParamMessage");
}

ParamMessage::~ParamMessage()
{

}
