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
    PyObject *pScriptPath = PyString_FromString(path.data());
    PyList_Append(pSysPath, pScriptPath);
    Py_DECREF(pScriptPath);

    m_pModule = NULL;

    pName = PyString_FromString("it4k");
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

void Scene::loadApp(const char *pAppName)
{
    PyObject *pName, *pValue, *pFunc;
    if(m_pModule == NULL)
    {
        pName = PyString_FromString(pAppName);
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
    {
        pFunc = PyObject_GetAttrString(m_pModule, "init");

        if(pFunc && PyCallable_Check(pFunc))
        {
            pValue = PyObject_CallObject(pFunc, 0);
            if(pValue != NULL)
            {
                //printf("Result of init: %ld\n", PyInt_AsLong(pValue));
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

void Scene::initializeGL()
{
    initializeOpenGLFunctions();
}

void Scene::resizeGL(int w, int h)
{
    PyObject *pValue, *pFunc, *pArgs;

    if(m_pIT4KModule)
    {
        pFunc = PyObject_GetAttrString(m_pIT4KModule, "resize");

        if(pFunc && PyCallable_Check(pFunc))
        {
            // TODO: do some checks here
            pArgs = PyTuple_New(2);
            pValue = PyInt_FromLong(w);
            PyTuple_SetItem(pArgs, 0, pValue);
            pValue = PyInt_FromLong(h);
            PyTuple_SetItem(pArgs, 1, pValue);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
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

void Scene::paintGL()
{
    PyObject *pValue, *pFunc;

    if(m_pIT4KModule)
    {
        pFunc = PyObject_GetAttrString(m_pIT4KModule, "draw");

        if(pFunc && PyCallable_Check(pFunc))
        {
            pValue = PyObject_CallObject(pFunc, 0);
            if(pValue != NULL)
            {
                //printf("Result of draw: %ld\n", PyInt_AsLong(pValue));
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

void Scene::sendGO()
{
    PyObject *pValue, *pFunc;

    if(m_pIT4KModule)
    {
        pFunc = PyObject_GetAttrString(m_pIT4KModule, "start");

        if(pFunc && PyCallable_Check(pFunc))
        {
            pValue = PyObject_CallObject(pFunc, 0);
            if(pValue != NULL)
            {
                //printf("Result of draw: %ld\n", PyInt_AsLong(pValue));
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

void Scene::mousePressEvent(QMouseEvent* event)
{
    PyObject *pValue, *pFunc, *pArgs;

    if(m_pIT4KModule)
    {
        pFunc = PyObject_GetAttrString(m_pIT4KModule, "mouse_press");

        if(pFunc && PyCallable_Check(pFunc))
        {
            // TODO: do some checks here
            pArgs = PyTuple_New(4);
            pValue = PyInt_FromLong(event->x());
            PyTuple_SetItem(pArgs, 0, pValue);
            pValue = PyInt_FromLong(height() - event->y());
            PyTuple_SetItem(pArgs, 1, pValue);
            pValue = PyInt_FromLong(0);
            PyTuple_SetItem(pArgs, 2, pValue);
            pValue = PyInt_FromLong(0);
            PyTuple_SetItem(pArgs, 3, pValue);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
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

    _prevMouseX = event->x();
    _prevMouseY = height() - event->y();
}

void Scene::mouseReleaseEvent(QMouseEvent* event)
{
    PyObject *pValue, *pFunc, *pArgs;

    if(m_pIT4KModule)
    {
        pFunc = PyObject_GetAttrString(m_pIT4KModule, "mouse_release");

        if(pFunc && PyCallable_Check(pFunc))
        {
            // TODO: do some checks here
            pArgs = PyTuple_New(4);
            pValue = PyInt_FromLong(event->x());
            PyTuple_SetItem(pArgs, 0, pValue);
            pValue = PyInt_FromLong(height() - event->y());
            PyTuple_SetItem(pArgs, 1, pValue);
            pValue = PyInt_FromLong(0);
            PyTuple_SetItem(pArgs, 2, pValue);
            pValue = PyInt_FromLong(0);
            PyTuple_SetItem(pArgs, 3, pValue);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
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

void Scene::mouseMoveEvent(QMouseEvent* event)
{
    PyObject *pValue, *pFunc, *pArgs;

    if(m_pIT4KModule)
    {
        pFunc = PyObject_GetAttrString(m_pIT4KModule, "mouse_drag");

        if(pFunc && PyCallable_Check(pFunc))
        {
            // TODO: do some checks here
            pArgs = PyTuple_New(6);
            pValue = PyInt_FromLong(event->x());
            PyTuple_SetItem(pArgs, 0, pValue);
            pValue = PyInt_FromLong(height() - event->y());
            PyTuple_SetItem(pArgs, 1, pValue);
            pValue = PyInt_FromLong(event->x() - _prevMouseX);
            PyTuple_SetItem(pArgs, 2, pValue);
            pValue = PyInt_FromLong(height() - event->y() - _prevMouseY);
            PyTuple_SetItem(pArgs, 3, pValue);
            pValue = PyInt_FromLong(0);
            PyTuple_SetItem(pArgs, 4, pValue);
            pValue = PyInt_FromLong(0);
            PyTuple_SetItem(pArgs, 5, pValue);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
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

    _prevMouseX = event->x();
    _prevMouseY = height() - event->y();
}
