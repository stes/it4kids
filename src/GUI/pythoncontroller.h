#ifndef PYTHONCONTROLLER_H
#define PYTHONCONTROLLER_H

#undef slots
#include <Python.h>
#define slots Q_SLOTS

class PythonController
{
    PyObject *m_pIT4KModule;
    PyObject *m_pModule;

    void callMethod(PyObject *pModule, const char *pName, PyObject *pArgs = NULL);

public:
    PythonController();

    void loadApp(const char *pAppName);
    void sendStart();
    void sendStop();
    void sendDraw();
    void sendResize(int w, int h);
    void sendMousePress(int x, int y);
    void sendMouseRelease(int x, int y);
    void sendMouseMove(int x, int y, int dx, int dy);
};

#endif // PYTHONCONTROLLER_H
