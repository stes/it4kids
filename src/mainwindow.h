#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "audio/audioengine.h"
#include "codegenerator.h"
#include "pythoncontroller.h"
#include "saveloadclass.h"

class Costume;
class DragElemCategory;
class DraggableElement;
class ScriptAreaWidget;
class Sprite;
class Teacher;
class Student;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    const SpriteVector* getSpriteVector();
    void addSprite(Sprite *sprite);
    Sprite* getCurrentSprite() { return _currentSprite; }
    Sprite* getBackgroundSprite() { return _backgroundSprite; }

    QRect getScriptAreaRect();

    ~MainWindow();

    QString getTempPath();

    void reloadCodeAll();
    void reloadCodeSprite(Sprite *sprite);

    void initPython();
    void reindexMedia();

signals:
    void currentSpriteChanged(Sprite* sprite);
    void newSound();
    void newCostume();
    void currentStudentChanged(Student* student);
    void currentTeacherChanged(Teacher* teacher);

private slots:
    void on_soundFromFile_clicked();
    void on_costumeFromFile_clicked();
    void on_buttonAddDragElem_clicked();
    void on_spriteFromFile_clicked();

    void on_buttonScriptStart_clicked();
    void on_buttonScriptStop_clicked();

    void on_logInTeacher_clicked();

    void changeCurrentSprite(Sprite* sprite);
    void setCurrentCostume(Costume* costume);
    void setCurrentStudent(bool);

    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionPython_triggered();

private:
    void InitializeDragElem(const QString& path);
    DragElemCategory* getCategoryByName(const QString& name);
    void cleanTempDir();

    Ui::MainWindow *ui;

#ifdef CONF_CODE_EDITOR
    class QsciScintilla *_codeEditor;
#endif

    Sprite* _currentSprite;
    Sprite* _backgroundSprite;

    bool _loading;

    AudioEngine _audioEngine;
    CodeGenerator _Cgen;
    PythonController _pyController;
	SaveLoadClass _slc;

    QDir _appDir;
    QDir _tmpDir;

    Teacher* _currentTeacher;
    Student* _currentStudent;
};

#endif // MAINWINDOW_H
