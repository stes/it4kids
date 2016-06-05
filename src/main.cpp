#include <QApplication>
#include <QFile>
#include <QStyle>
#include <QDebug>

#include "mainwindow.h"
#include "sprite.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile styleSheet(":/style.qss");
    styleSheet.open(QFile::ReadOnly);
    QString _styleSheet = QLatin1String(styleSheet.readAll());
    w.setStyleSheet(_styleSheet);

    w.showMaximized();

    return a.exec();
}
