#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Qsci/qsciscintilla.h>

class AudioEngine;
class DragElemCategory;
class DragableElement;
class ScriptAreaWidget;
class Sprite;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

signals:
    void newSound();
    void newCostume();

private slots:
    void on_soundFromFile_clicked();
    void on_costumeFromFile_clicked();

private:
    void InitializeDragElem(const QString& path);
    DragElemCategory* GetCategoryByName(const QString& name);

    Ui::MainWindow *ui;

    AudioEngine* _audioEngine;
    Sprite* _currentSprite;

    Sprite* _backgroundSprite;
};

#endif // MAINWINDOW_H
