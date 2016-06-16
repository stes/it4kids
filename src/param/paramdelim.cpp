#include <QComboBox>

#include "paramdelim.h"

ParamDelim::ParamDelim(QWidget *parent) : ParamComboBox(parent)
{
    _comboBox->addItem("letter");
    _comboBox->addItem("whitespace");
    _comboBox->addItem("line");
    _comboBox->addItem("tab");
    _comboBox->addItem("cr");
}

ParamDelim::~ParamDelim()
{
}
