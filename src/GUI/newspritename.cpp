#include "newspritename.h"
#include "ui_newspritename.h"

NewSpriteName::NewSpriteName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSpriteName)
{
    ui->setupUi(this);
}

NewSpriteName::~NewSpriteName()
{
    delete ui;
}

QString NewSpriteName::getName()
{
    return ui->nameEdit->text();
}
