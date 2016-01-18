#include "studentlist.h"

#include <QCheckBox>
#include <QVariant>

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

    QCheckBox* cBox = new QCheckBox(this);
    _gridLayout.addWidget(cBox, 1, 0);
    QLabel* name = new QLabel("Peter", this);
    _gridLayout.addWidget(name, 1, 1);
    QLabel* lastOnline = new QLabel("01.01.16");
    _gridLayout.addWidget(lastOnline, 1, 2);
    QLabel* currentProject = new QLabel("Maus zum Käse", this);
    _gridLayout.addWidget(currentProject, 1, 3);
}

