#include "studentlist.h"

#include <QRadioButton>
#include <QVariant>

#include "student.h"
#include "teacher.h"
#include "mainwindow.h"

extern MainWindow* _sMainWindow;

StudentList::StudentList(QWidget *parent) : QWidget(parent), _gridLayout(this)
{
    setLayout(&_gridLayout);
    _gridLayout.setContentsMargins(0, 0, 0, 0);
    _gridLayout.setSpacing(0);
    _selectionLabel.setText("Auswahl");
    _selectionLabel.setProperty("coloredcell", true);
    _gridLayout.addWidget(&_selectionLabel, 0, 0);
    _nameLabel.setText("Name");
    _nameLabel.setProperty("coloredcell", true);
    _gridLayout.addWidget(&_nameLabel, 0, 1);
    _lastOnlineLabel.setText("Zuletzt angemeldet");
    _lastOnlineLabel.setProperty("coloredcell", true);
    _gridLayout.addWidget(&_lastOnlineLabel, 0, 2);
    _currentProjectLabel.setText("Derzeitiges Projekt");
    _currentProjectLabel.setProperty("coloredcell", true);
    _gridLayout.addWidget(&_currentProjectLabel, 0, 3);
    setStyleSheet("*[coloredcell=\"true\"] {background-color:#9c9ea2; color: #ffffff; font-size: 16px;}");

}

void StudentList::currentTeacherChanged(Teacher* teacher)
{
    for(uint i = 0; i < teacher->getStudentVector()->size(); i++)
    {
        QRadioButton* rButton = new QRadioButton();
        connect(rButton, SIGNAL(toggled(bool)), _sMainWindow, SLOT(setCurrentStudent(bool)));
        _gridLayout.addWidget(rButton);
        _gridLayout.addWidget(rButton, i+1, 0);
        _gridLayout.addWidget(new QLabel(teacher->getStudentVector()->at(i)->getName()), i+1, 1);
        _gridLayout.addWidget(new QLabel(teacher->getStudentVector()->at(i)->getLastOnline()), i+1, 2);
        _gridLayout.addWidget(new QLabel(teacher->getStudentVector()->at(i)->getCurrentProject()), i+1, 3);
    }
}

