#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QMouseEvent>

class PythonController;

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

    PythonController *_pyController;

    int _prevMouseX;
    int _prevMouseY;


public:
    Scene(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void setPyController(PythonController *pyController) { _pyController = pyController; }

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // SCENE_H
