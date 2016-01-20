#ifndef COSTUME_H
#define COSTUME_H

#include <QImage>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

class Sprite;

class Costume : public QWidget
{
    Q_OBJECT
public:
    Costume(Sprite* parent = 0);

    bool open(const QString &fileName);
    inline QImage* getImage() {return &_costume;}
    inline void createBlank() { }
    inline QString getName() {return _name;}

signals:
    void costumeSelected(Costume* costume);

protected:
    void mousePressEvent(QMouseEvent*);

    QImage _costume;

    QVBoxLayout _layout;
    QPixmap _soundPixmap;
    QString _name;
    QLabel _nameLabel;
    QLabel _costumeLabel;
};

#endif // COSTUME_H
