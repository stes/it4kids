#ifndef COSTUME_H
#define COSTUME_H

#include <QImage>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <QDir>

class Sprite;

class Costume : public QWidget
{
    Q_OBJECT
public:
    Costume(Sprite* parent = 0);

    bool open(const QString &fileName, bool externFile = false);
    inline QImage* getImage() {return &_costume;}
    inline void createBlank() { }
    inline QString getName() {return _name;}
    inline QString getFilename() {return _filename;}

    void exportFile(const QDir &directory);

signals:
    void costumeSelected(Costume* costume);

protected:
    void mousePressEvent(QMouseEvent*);

    QImage _costume;

    QVBoxLayout _layout;
    QPixmap _soundPixmap;
    QString _name;
    QString _filename;
    QString _filepath;
    QLabel _nameLabel;
    QLabel _costumeLabel;
};

#endif // COSTUME_H
