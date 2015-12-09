#include "paramdelim.h"

ParamDelim::ParamDelim(QWidget *parent) : QComboBox(parent)
{
    addItem("letter");
    addItem("whitespace");
    addItem("line");
    addItem("tab");
    addItem("cr");
    #pragma message("Fix GetValue")
}

QString ParamDelim::getValue()
{
    return QString("ParamDelim");
}

ParamDelim::~ParamDelim()
{

}

