#include "paramlistid.h"

ParamListId::ParamListId(QWidget *parent) : QComboBox(parent)
{
    addItem("1");
    setMinimumWidth(30);
    //#warning "Add ListId list to ParamListId"
}

QString ParamListId::getValue()
{
    return QString("ParamListId");
}

ParamListId::~ParamListId()
{

}


