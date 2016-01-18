#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>

class StudentList : public QWidget
{
    Q_OBJECT
public:
    explicit StudentList(QWidget *parent = 0);

signals:

public slots:

protected:
    QGridLayout _gridLayout;
    QLabel _selectionLabel;
    QLabel _nameLabel;
    QLabel _lastOnlineLabel;
    QLabel _currentProjectLabel;
};

#endif // STUDENTLIST_H
