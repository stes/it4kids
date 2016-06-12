#ifndef PYTHONCONTROLLER_H
#define PYTHONCONTROLLER_H

#ifndef PyObject_HEAD
struct _object;
typedef _object PyObject;
#endif

class PythonController
{
    PyObject *_pIT4KApp;

    PyObject *callMethodWithReturn(PyObject *pObj, const char *pName, PyObject *pArgs = NULL);
    void callMethod(PyObject *pObj, const char *pName, PyObject *pArgs = NULL);

    PyObject *loadModuleFromStr(const char *pName, const char *pCodeStr);

public:
    PythonController();
    virtual ~PythonController();

    void addSysPath(const char *pPath);
    void addMediaPath(const char *pPath);

    void init();
    void loadEntity(const char *pModule, const char *pClass, const char *pCodeStr);

    void resetApp();
    void reindexMedia();

    void sendStart();
    void sendStop();
    void sendDraw();
    void sendResize(int w, int h);
    void sendMousePress(int x, int y);
    void sendMouseRelease(int x, int y);
    void sendMouseMove(int x, int y, int dx, int dy);
};

#endif // PYTHONCONTROLLER_H
