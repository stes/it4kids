#include "paramlistselec.h"

ParamListSelec::ParamListSelec(QWidget *parent) : QComboBox(parent)
{
    addItem("a");
    //#warning "Add ListSelec list to ParamListSelec"
}

QString ParamListSelec::getString() const
{
    return "ParamListSelec";
}

ParamListSelec::~ParamListSelec()
{

}

