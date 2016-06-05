#include <QTimer>

#include "scene.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    setFormat(format);

    _prevMouseX = 0;
    _prevMouseY = 0;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();
    // TODO: should not be here
    _pyController->loadApp("main");
}

void Scene::resizeGL(int w, int h)
{
    _pyController->sendResize(w, h);
}

void Scene::paintGL()
{
    _pyController->sendDraw();
}

void Scene::mousePressEvent(QMouseEvent* event)
{
    _pyController->sendMousePress(event->x(), height() - event->y());

    _prevMouseX = event->x();
    _prevMouseY = height() - event->y();
}

void Scene::mouseReleaseEvent(QMouseEvent* event)
{
    _pyController->sendMouseRelease(event->x(), height() - event->y());
}

void Scene::mouseMoveEvent(QMouseEvent* event)
{
    _pyController->sendMouseMove(event->x(), height() - event->y(), event->x() - _prevMouseX, height() - event->y() - _prevMouseY);

    _prevMouseX = event->x();
    _prevMouseY = height() - event->y();
}
