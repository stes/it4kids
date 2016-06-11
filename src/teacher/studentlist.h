#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>

class Teacher;

class StudentList : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit StudentList(QWidget *parent = 0);

public slots:
    void currentTeacherChanged(Teacher* teacher);
protected:
    QGridLayout _gridLayout;
    QLabel _selectionLabel;
    QLabel _nameLabel;
    QLabel _lastOnlineLabel;
    QLabel _currentProjectLabel;
};

#endif // STUDENTLIST_H
