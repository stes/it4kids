#include "paramdelim.h"

ParamDelim::ParamDelim(QWidget *parent) : QComboBox(parent)
{
    addItem("letter");
    addItem("whitespace");
    addItem("line");
    addItem("tab");
    addItem("cr");
}

QString ParamDelim::getValue()
{
    return currentText();
}

ParamDelim::~ParamDelim()
{

}

