#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QMouseEvent>
#undef slots
#include <Python.h>
#define slots Q_SLOTS

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

    PyObject *m_pIT4KModule;
    PyObject *m_pModule;

    int _prevMouseX;
    int _prevMouseY;

    void callMethod(PyObject *pModule, const char *pName, PyObject *pArgs = NULL);

public:
    Scene(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    void loadApp(const char *pAppName);
    void sendStart();
    void sendStop();
};

#endif // SCENE_H
