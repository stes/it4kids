#include "paramdelim.h"

ParamDelim::ParamDelim(QWidget *parent) : QComboBox(parent)
{
    addItem("letter");
    addItem("whitespace");
    addItem("line");
    addItem("tab");
    addItem("cr");
}

bool ParamDelim::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamDelim::getString() const
{
    return currentText();
}

ParamDelim::~ParamDelim()
{

}

