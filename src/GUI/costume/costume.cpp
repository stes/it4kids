#include "costume.h"

#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* _sMainWindow;

Costume::Costume(Sprite* parent) : QWidget(parent), _costume(400, 400, QImage::Format_ARGB32)
{
    connect(this, SIGNAL(costumeSelected(Costume*)), parent, SLOT(setCurrentCostume(Costume*)));
    connect(this, SIGNAL(costumeSelected(Costume*)), _sMainWindow, SLOT(setCurrentCostume(Costume*)));

    setLayout(&_layout);
    setFixedWidth(88);
    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    _layout.setContentsMargins(0, 0, 0, 0);

    _layout.addWidget(&_costumeLabel);
    _costumeLabel.setFixedSize(40, 40);

    _layout.addWidget(&_nameLabel);
    _nameLabel.setAlignment(Qt::AlignHCenter);

    _costume.fill(Qt::red);
    _costumeLabel.setPixmap(QPixmap::fromImage(_costume).scaled(40, 40));
}

bool Costume::open(const QString &fileName)
{
    QStringList list = fileName.split("/");
    _name = list.last();
    _name.truncate(_name.length() - 4);
    _nameLabel.setText(_name);
    _costume.load(fileName);
    _costumeLabel.setPixmap(QPixmap::fromImage(_costume).scaled(40, 40));
    hide();
    return true;
}

void Costume::mousePressEvent(QMouseEvent *)
{
    emit costumeSelected(this);
}
