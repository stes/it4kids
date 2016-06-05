#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <Qsci/qsciscintilla.h>

#include "audio/audioengine.h"
#include "teacher/student.h"
#include "codegenerator.h"
#include "pythoncontroller.h"
#include "spriteselect.h"

class AudioEngine;
class Costume;
class DragElemCategory;
class DragableElement;
class ScriptAreaWidget;
class Sprite;
class Teacher;
class Student;


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
    Sprite *getBackgroundSprite() { return _backgroundSprite; }
    DragableElement* createNewElement(QString s);

    ~MainWindow();

    inline Sprite* getCurrentSprite() {return _currentSprite;}

    void reloadCode();

signals:
    void currentSpriteChanged(Sprite* sprite);
    void newSound();
    void newCostume();
    void currentStudentChanged(Student* student);
    void currentTeacherChanged(Teacher* teacher);

private slots:
    void on_soundFromFile_clicked();
    void on_costumeFromFile_clicked();
    void on_buttonFile_clicked();
    void on_buttonEdit_clicked();
    void on_buttonAddDragElem_clicked();
    void on_spriteFromFile_clicked();

    void on_buttonScriptStart_clicked();
    void on_buttonScriptStop_clicked();

    void on_logInTeacher_clicked();

    void on_scriptArea_customContextMenuRequested(const QPoint &pos);
    void on_listAddDragElem_customContextMenuRequested(const QPoint &pos);

    void changeCurrentSprite(Sprite* sprite);
    void eraseItemAddDragElem();
    void setCurrentCostume(Costume* costume);
    void setCurrentStudent(bool);
    void dragElemContextMenuRequested(const QPoint &pos, DragableElement* elem);
    void spriteContextMenuRequested(const QPoint &pos, Sprite* sprite);
    void on_scene_customContextMenuRequested(const QPoint &pos);

private:
    void InitializeDragElem(const QString& path);
    DragElemCategory* GetCategoryByName(const QString& name);

    Ui::MainWindow *ui;

    Sprite* _currentSprite;
    Sprite* _backgroundSprite;

    QMenu _fileMenu;
    QMenu _editMenu;

    AudioEngine _audioEngine;
    CodeGenerator _Cgen;
    PythonController _pyController;

    std::vector<DragableElement*> _LoadableDrags;

    Teacher* _currentTeacher;
    Student* _currentStudent;
};

#endif // MAINWINDOW_H
