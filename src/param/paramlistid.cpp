#include <QComboBox>

#include "paramlistid.h"

// TODO: round corners
ParamListId::ParamListId(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("1");
    _comboBox->setMinimumWidth(30);
    //#warning "Add ListId list to ParamListId"
}

ParamListId::~ParamListId()
{
}
