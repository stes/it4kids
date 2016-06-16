#include <QComboBox>

#include "parammessage.h"

ParamMessage::ParamMessage(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("message1");
    //#warning "Add Message list to ParamMessage"
}

ParamMessage::~ParamMessage()
{
}
