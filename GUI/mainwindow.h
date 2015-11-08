#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainterPath>

#include "dragelemcategory.h"
#include "commandde.h"
#include "hatde.h"
#include "wrapperde.h"
#include "predicatede.h"

class DragElemCategory;

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
