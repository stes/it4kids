#include "paramlistselec.h"

ParamListSelec::ParamListSelec(QWidget *parent) : QComboBox(parent)
{
    addItem("a");
    //#warning "Add ListSelec list to ParamListSelec"
}

QString ParamListSelec::getValue()
{
    return QString("ParamListSelec");
}

ParamListSelec::~ParamListSelec()
{

}

