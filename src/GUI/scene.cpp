#include <QTimer>
#include <QDir>

#include "scene.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    setFormat(format);

    _prevMouseX = 0;
    _prevMouseY = 0;

    PyObject *pName;

    Py_Initialize();

    PyObject *pSysPath = PySys_GetObject((char*)"path");
    QByteArray path = QDir::currentPath().append("/python").toLatin1();
    PyObject *pScriptPath = PyUnicode_DecodeFSDefault(path.data());
    PyList_Append(pSysPath, pScriptPath);
    Py_DECREF(pScriptPath);

    m_pModule = NULL;

    pName = PyUnicode_DecodeFSDefault("it4k");
    m_pIT4KModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if(m_pIT4KModule == NULL)
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load it4k module\n");
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}

void Scene::callMethod(PyObject *pModule, const char *pName, PyObject *pArgs)
{
    PyObject *pValue, *pFunc;

    if(pModule)
    {
        pFunc = PyObject_GetAttrString(pModule, pName);

        if(pFunc && PyCallable_Check(pFunc))
        {
            // TODO: do some checks here
            pValue = PyObject_CallObject(pFunc, pArgs);
            if(pValue != NULL)
            {
                //printf("Result of resize: %ld\n", PyInt_AsLong(pValue));
                Py_DECREF(pValue);
            }
            else
            {
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
            }
        }
        else
        {
            if(PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function\n");
        }
        Py_XDECREF(pFunc);
    }
}

void Scene::loadApp(const char *pAppName)
{
    if(m_pModule == NULL)
    {
        PyObject *pName = PyUnicode_DecodeFSDefault(pAppName);
        m_pModule = PyImport_Import(pName);
        Py_DECREF(pName);
    }
    else
        m_pModule = PyImport_ReloadModule(m_pModule);

    if(m_pModule == NULL)
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load module\n");
    }
    else
        callMethod(m_pModule, "init");
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();
}

void Scene::resizeGL(int w, int h)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(2);
    pValue = PyLong_FromLong(w);
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(h);
    PyTuple_SetItem(pArgs, 1, pValue);

    callMethod(m_pIT4KModule, "resize", pArgs);
    Py_DECREF(pArgs);
}

void Scene::paintGL()
{
    callMethod(m_pIT4KModule, "draw");
}

void Scene::sendStart()
{
    callMethod(m_pIT4KModule, "start");
}

void Scene::sendStop()
{
    callMethod(m_pIT4KModule, "stop");
}

void Scene::mousePressEvent(QMouseEvent* event)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(4);
    pValue = PyLong_FromLong(event->x());
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(height() - event->y());
    PyTuple_SetItem(pArgs, 1, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 2, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 3, pValue);

    callMethod(m_pIT4KModule, "mouse_press", pArgs);
    Py_DECREF(pArgs);

    _prevMouseX = event->x();
    _prevMouseY = height() - event->y();
}

void Scene::mouseReleaseEvent(QMouseEvent* event)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(4);
    pValue = PyLong_FromLong(event->x());
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(height() - event->y());
    PyTuple_SetItem(pArgs, 1, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 2, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 3, pValue);

    callMethod(m_pIT4KModule, "mouse_release", pArgs);
    Py_DECREF(pArgs);
}

void Scene::mouseMoveEvent(QMouseEvent* event)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(6);
    pValue = PyLong_FromLong(event->x());
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(height() - event->y());
    PyTuple_SetItem(pArgs, 1, pValue);
    pValue = PyLong_FromLong(event->x() - _prevMouseX);
    PyTuple_SetItem(pArgs, 2, pValue);
    pValue = PyLong_FromLong(height() - event->y() - _prevMouseY);
    PyTuple_SetItem(pArgs, 3, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 4, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 5, pValue);

    callMethod(m_pIT4KModule, "mouse_drag", pArgs);
    Py_DECREF(pArgs);

    _prevMouseX = event->x();
    _prevMouseY = height() - event->y();
}
