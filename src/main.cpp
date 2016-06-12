#include <QApplication>
#include <QFile>
#include <QStyle>
#include <QTranslator>
#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("IT4Kids");

    QTranslator translator;
    if (translator.load(QLocale(), QLatin1String("editor"), QLatin1String("_"), QLatin1String(":/translations")))
        app.installTranslator(&translator);

    MainWindow window;

    QFile styleSheet(":/style.qss");
    styleSheet.open(QFile::ReadOnly);
    QString _styleSheet = QLatin1String(styleSheet.readAll());
    window.setStyleSheet(_styleSheet);

    window.showMaximized();

    return app.exec();
}
