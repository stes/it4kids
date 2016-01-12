#ifndef COSTUME_H
#define COSTUME_H

#include <QImage>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

class Costume : public QWidget
{
    Q_OBJECT
public:
    Costume(QWidget* parent = 0);

    bool open(const QString &fileName);
    inline QImage* getImage() {return &_costume;}

protected:
    QImage _costume;

    QVBoxLayout _layout;
    QPixmap _soundPixmap;
    QString _name;
    QLabel _nameLabel;
    QLabel _costumeLabel;
};

#endif // COSTUME_H
