#include <QTemporaryFile>
#include <QFileInfo>

#include "costume.h"

#include "mainwindow.h"
#include "sprite.h"

extern MainWindow* sMainWindow;

Costume::Costume(Sprite* parent) : QWidget(parent), _costume(400, 400, QImage::Format_ARGB32)
{
    connect(this, SIGNAL(costumeSelected(Costume*)), parent, SLOT(setCurrentCostume(Costume*)));
    connect(this, SIGNAL(costumeSelected(Costume*)), sMainWindow, SLOT(setCurrentCostume(Costume*)));

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

bool Costume::open(const QString &fileName, bool externFile)
{
    QFileInfo info(fileName);
    _name = info.baseName();
    _nameLabel.setText(_name);

    QString tmpFile;
    if(externFile)
    {
        QTemporaryFile tmp(sMainWindow->getTempPath() + "/costume");
        if (tmp.open())
            tmpFile = tmp.fileName();
    }
    
    if (!tmpFile.isEmpty())
    {
        QFileInfo tmpInfo(tmpFile);
        _filepath = tmpFile;
        _filename = tmpInfo.fileName();
        QFile::copy(fileName, _filepath);
        sMainWindow->reindexMedia();
    }
    else
    {
        _filepath = fileName;
        _filename = fileName;
    }

    _costume.load(fileName);
    _costumeLabel.setPixmap(QPixmap::fromImage(_costume).scaled(40, 40));
    hide();
    return true;
}

void Costume::exportFile(const QDir &directory)
{
    QString newFilePath = directory.filePath(_filename);
    QFileInfo info(newFilePath);
    directory.mkpath(info.path());
    QFile::copy(_filepath, newFilePath);
}

void Costume::mousePressEvent(QMouseEvent *)
{
    emit costumeSelected(this);
}
