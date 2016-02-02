#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <Qsci/qsciscintilla.h>
#include "codegenerator.h"

#include "spriteselect.h"

class AudioEngine;
class Costume;
class DragElemCategory;
class DragableElement;
class ScriptAreaWidget;
class Sprite;


typedef std::vector<Sprite*> SpriteVector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    SpriteVector* getSpriteVector();

    ~MainWindow();

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
    void on_spriteFromFile_clicked();

    void on_buttonScriptStart_clicked();
    void on_buttonScriptStop_clicked();

    void changeCurrentSprite(Sprite* sprite);
    void customContextMenuRequestedAddDragElem(const QPoint &pos);
    void eraseItemAddDragElem();
    void setCurrentCostume(Costume* costume);
private:
    void InitializeDragElem(const QString& path);
    DragElemCategory* GetCategoryByName(const QString& name);

    Ui::MainWindow *ui;

    AudioEngine* _audioEngine;
    Sprite* _currentSprite;

    Sprite* _backgroundSprite;

    QMenu _dateiMenu;
    QMenu _bearbeitenMenu;

    CodeGenerator * _Cgen;
};

#endif // MAINWINDOW_H
