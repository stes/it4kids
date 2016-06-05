#ifndef TEACHERLOGIN_H
#define TEACHERLOGIN_H

#include <QDialog>

namespace Ui {
class TeacherLogIn;
}

class TeacherLogIn : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherLogIn(QWidget *parent = 0);
    QString getUsername();
    QString getPassword();
    ~TeacherLogIn();

private:
    Ui::TeacherLogIn *ui;
};

#endif // TEACHERLOGIN_H
