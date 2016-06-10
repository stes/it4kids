#ifndef STUDENT_H
#define STUDENT_H

#include <vector>

#include <QLabel>

#include "mainwindow.h"


class DraggableElement;

class Student
{
public:
    Student(const QString& name, const QString& lastOnline = QString("01.01.2016"), const QString& currentProject = QString("Maus zum Käse"));

    inline void setName(const QString& name) { _nameLabel = name; }
    inline QString getName() { return _nameLabel; }
    inline void setLastOnline(const QString& lastOnline)  { _lastOnlineLabel = lastOnline; }
    inline QString getLastOnline() { return _lastOnlineLabel; }
    inline void setCurrentProject(const QString& currentProject) { _currentProjectLabel = currentProject; }
    inline QString getCurrentProject() { return _currentProjectLabel; }

    inline bool isOnline() { return true; }

    inline void addAddDragElem(const QString &elem) { _addDragElem.push_back(elem); }
    inline std::vector<QString>* getAddDragElemVector() { return &_addDragElem; }

protected:
    QString _nameLabel;
    QString _lastOnlineLabel;
    QString _currentProjectLabel;

    std::vector<QString> _addDragElem;
};

#endif // STUDENT_H
