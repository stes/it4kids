#include "teacherlogin.h"
#include "ui_teacherlogin.h"

TeacherLogIn::TeacherLogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherLogIn)
{
    ui->setupUi(this);
}

QString TeacherLogIn::getUsername()
{
    return ui->username->text();
}

QString TeacherLogIn::getPassword()
{
    return ui->password->text();
}

TeacherLogIn::~TeacherLogIn()
{
    delete ui;
}
