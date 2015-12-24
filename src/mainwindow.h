#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DragElemCategory;
class DragableElement;
class ScriptAreaWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
private:
    void InitializeDragElem(const QString& path);
    DragElemCategory* GetCategoryByName(const QString& name);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
