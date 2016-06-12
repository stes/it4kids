#include <Python.h>

#include "pythoncontroller.h"

PythonController::PythonController() : _pIT4KApp(0)
{
    Py_Initialize();
}

PythonController::~PythonController()
{
    Py_Finalize();
}

void PythonController::addSysPath(const char *pPath)
{
    PyObject *pSysPath = PySys_GetObject("path");
    PyObject *pScriptPath = PyUnicode_DecodeFSDefault(pPath);
    PyList_Append(pSysPath, pScriptPath);
    Py_DECREF(pScriptPath);
}

void PythonController::addMediaPath(const char *pPath)
{
    PyObject *pMediaPath = PyUnicode_DecodeFSDefault(pPath);
    PyObject *pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, pMediaPath);

    callMethod(_pIT4KApp, "add_media_path", pArgs);
    Py_DECREF(pArgs);
}

void PythonController::init()
{
    PyObject *pName = PyUnicode_DecodeFSDefault("it4k.embed");
    PyObject *pIT4KModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pIT4KModule == NULL)
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load it4k module\n");
        return;
    }

    _pIT4KApp = callMethodWithReturn(pIT4KModule, "init");
    Py_DECREF(pIT4KModule);
}

void PythonController::loadEntity(const char *pModule, const char *pClass, const char *pCodeStr)
{
    PyObject *pEntModule = loadModuleFromStr(pModule, pCodeStr);
    if(!pEntModule)
        return;

    PyObject *pEntInstance = callMethodWithReturn(pEntModule, pClass);
    Py_DECREF(pEntModule);
    if (!pEntInstance)
        return;

    PyObject *pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, pEntInstance);
    
    callMethod(_pIT4KApp, "add_entity", pArgs);
    Py_DECREF(pArgs);
}

PyObject *PythonController::callMethodWithReturn(PyObject *pObj, const char *pName, PyObject *pArgs)
{
    PyObject *pValue = 0, *pFunc;

    if(pObj)
    {
        pFunc = PyObject_GetAttrString(pObj, pName);

        if(pFunc && PyCallable_Check(pFunc))
        {
            // TODO: do some checks here
            pValue = PyObject_CallObject(pFunc, pArgs);
            if(pValue == NULL)
            {
                PyErr_Print();
                fprintf(stderr, "Call failed: %s\n", pName);
            }
        }
        else
        {
            if(PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function %s\n", pName);
        }
        Py_XDECREF(pFunc);
    }

    return pValue;
}

void PythonController::callMethod(PyObject *pObj, const char *pName, PyObject *pArgs)
{
    PyObject *pValue = callMethodWithReturn(pObj, pName, pArgs);
    Py_XDECREF(pValue);
}

PyObject *PythonController::loadModuleFromStr(const char *pName, const char *pCodeStr)
{
    PyObject *pCode = Py_CompileString(pCodeStr, pName, Py_file_input);
    PyObject *pModule = PyImport_ExecCodeModule(pName, pCode);
    Py_XDECREF(pCode);

    if (pModule == NULL)
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load module %s\n", pName);
    }

    return pModule;
}

void PythonController::resetApp()
{
    callMethod(_pIT4KApp, "reset");
}

void PythonController::reindexMedia()
{
    callMethod(_pIT4KApp, "reindex_media");
}

void PythonController::sendStart()
{
    callMethod(_pIT4KApp, "start");
}

void PythonController::sendStop()
{
    callMethod(_pIT4KApp, "stop");
}

void PythonController::sendDraw()
{
    callMethod(_pIT4KApp, "draw");
}

void PythonController::sendResize(int w, int h)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(2);
    pValue = PyLong_FromLong(w);
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(h);
    PyTuple_SetItem(pArgs, 1, pValue);

    callMethod(_pIT4KApp, "resize", pArgs);
    Py_DECREF(pArgs);
}

void PythonController::sendMousePress(int x, int y)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(4);
    pValue = PyLong_FromLong(x);
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(y);
    PyTuple_SetItem(pArgs, 1, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 2, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 3, pValue);

    callMethod(_pIT4KApp, "mouse_press", pArgs);
    Py_DECREF(pArgs);
}

void PythonController::sendMouseRelease(int x, int y)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(4);
    pValue = PyLong_FromLong(x);
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(y);
    PyTuple_SetItem(pArgs, 1, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 2, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 3, pValue);

    callMethod(_pIT4KApp, "mouse_release", pArgs);
    Py_DECREF(pArgs);
}

void PythonController::sendMouseMove(int x, int y, int dx, int dy)
{
    PyObject *pValue, *pArgs;
    pArgs = PyTuple_New(6);
    pValue = PyLong_FromLong(x);
    PyTuple_SetItem(pArgs, 0, pValue);
    pValue = PyLong_FromLong(y);
    PyTuple_SetItem(pArgs, 1, pValue);
    pValue = PyLong_FromLong(dx);
    PyTuple_SetItem(pArgs, 2, pValue);
    pValue = PyLong_FromLong(dy);
    PyTuple_SetItem(pArgs, 3, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 4, pValue);
    pValue = PyLong_FromLong(0);
    PyTuple_SetItem(pArgs, 5, pValue);

    callMethod(_pIT4KApp, "mouse_drag", pArgs);
    Py_DECREF(pArgs);
}
