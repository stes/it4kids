#include <QComboBox>

#include "paramlistselec.h"

ParamListSelec::ParamListSelec(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("a");
    //#warning "Add ListSelec list to ParamListSelec"
}
ParamListSelec::~ParamListSelec()
{

}
