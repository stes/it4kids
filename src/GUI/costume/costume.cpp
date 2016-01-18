#include "costume.h"

Costume::Costume(QWidget* parent) : QWidget(parent)
{
    setLayout(&_layout);
    setFixedWidth(88);
    _layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    _layout.setContentsMargins(0, 0, 0, 0);

    _layout.addWidget(&_costumeLabel);
    _costumeLabel.setFixedSize(40, 40);

    _layout.addWidget(&_nameLabel);
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
