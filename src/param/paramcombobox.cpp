#include <QComboBox>

#include "paramcombobox.h"

ParamComboBox::ParamComboBox(QWidget *parent) : _comboBox(new QComboBox(parent))
{
}

bool ParamComboBox::setValue(const QString &val)
{
    _comboBox->setCurrentText(val);
    return true;
}

QString ParamComboBox::getString() const
{
    return _comboBox->currentText();
}

QWidget* ParamComboBox::getWidget()
{
    return _comboBox;
};

void ParamComboBox::addOption(const QString &text)
{
    _comboBox->addItem(text);
}

void ParamComboBox::setModel(QAbstractItemModel *model)
{
    _comboBox->setModel(model);
}

ParamComboBox::~ParamComboBox()
{
}
