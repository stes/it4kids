#include "parameffect.h"

ParamEffect::ParamEffect(QWidget *parent) : QComboBox(parent)
{
    addItem("ghost");
    addItem("brightness");
    addItem("negative");
    addItem("comic");
    addItem("duplicate");
    addItem("confetti");
}

bool ParamEffect::setValue(const QString &val)
{
    setCurrentText(val);
    return true;
}

QString ParamEffect::getString() const
{
    return currentText();
}

ParamEffect::~ParamEffect()
{

}
