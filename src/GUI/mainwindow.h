#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <Qsci/qsciscintilla.h>

#include "spriteselect.h"

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

    SpriteVector* getSpriteVector();
    inline Sprite* getCurrentSprite() {return _currentSprite;}

signals:
    void currentSpriteChanged(Sprite* sprite);
    void newSound();
    void newCostume();

private slots:
    void on_soundFromFile_clicked();
    void on_costumeFromFile_clicked();
    void on_buttonFile_clicked();
    void on_buttonEdit_clicked();
    void on_buttonAddDragElem_clicked();

    void customContextMenuRequestedAddDragElem(const QPoint &pos);
    void eraseItemAddDragElem();
    void on_MainWindow_currentSpriteChanged(Sprite *);
private:
    void InitializeDragElem(const QString& path);
    DragElemCategory* GetCategoryByName(const QString& name);

    Ui::MainWindow *ui;

    AudioEngine* _audioEngine;
    Sprite* _currentSprite;

    Sprite* _backgroundSprite;

    QMenu _dateiMenu;
    QMenu _bearbeitenMenu;
};

#endif // MAINWINDOW_H
