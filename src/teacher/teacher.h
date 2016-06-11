#ifndef TEACHER_H
#define TEACHER_H

#include <vector>

#include <QString>

class Student;

typedef std::vector<Student*> StudentVector;

class Teacher
{
public:
    Teacher(const QString& name, const QString& groupName);

    inline void addStudent(Student* student) { _studentVector.push_back(student); }
    inline StudentVector* getStudentVector() { return &_studentVector; }
    inline void setGroupName(const QString& groupName) { _groupName = groupName; }
    inline QString getGroupName() {return _groupName; }

    inline QString getName() { return _name; }

protected:
    StudentVector _studentVector;

    QString _name;
    QString _groupName;
};

#endif // TEACHER_H
