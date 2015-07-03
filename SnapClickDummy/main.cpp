#include <QApplication>
#include "snapmainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    SnapMainWindow* w = new SnapMainWindow();

    return app.exec();
}
