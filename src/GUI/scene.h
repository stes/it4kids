#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <Python.h>

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

    PyObject *m_pIT4KModule;
    PyObject *m_pModule;

    int _prevMouseX;
    int _prevMouseY;

public:
    Scene(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    void loadApp(const char *pAppName);
    void sendGO();
    void reset();
};

#endif // SCENE_H
