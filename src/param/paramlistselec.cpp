#include "paramlistselec.h"

ParamListSelec::ParamListSelec(QWidget *parent) : QComboBox(parent)
{
    addItem("a");
    //#warning "Add ListSelec list to ParamListSelec"
}

QString ParamListSelec::getValue()
{
    return addQuotes("ParamListSelec");
}

ParamListSelec::~ParamListSelec()
{

}

