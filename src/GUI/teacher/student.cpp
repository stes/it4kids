#include <QApplication>

#include "student.h"

Student::Student(const QString &name, const QString &lastOnline, const QString &currentProject)
{
    setName(name);
    setLastOnline(lastOnline);
    setCurrentProject(currentProject);
    //QObject::connect(QApplication::activeWindow(), )
}

