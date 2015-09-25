#include "dragableelement.h"
#include <QDebug>

DragableElement::DragableElement(const QString& text, const QColor& color, QWidget* scriptAreaWidget, QWidget* parent) :
    QWidget(parent), _text(text), _color(color), _scriptAreaWidget(scriptAreaWidget), _dragged(false)
{
    QLabel* content = new QLabel(this);
    content->setStyleSheet("background-color: none;");

    QHBoxLayout* layout = new QHBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(2);
    _width = 0;
    QStringList stringList = text.split("*", QString::SkipEmptyParts);
    for(int i = 0; i < stringList.size(); i++)
    {
        if(stringList.at(i).contains("QPixmap("))
        {
            QString pixmapPath = stringList.at(i);
            pixmapPath.remove(-1, 1);
            pixmapPath.remove(0, 8);
            QLabel* pixmap = new QLabel(this);
            QPixmap image(pixmapPath);
            pixmap->setPixmap(image.scaled(15, 15, Qt::KeepAspectRatio));
            pixmap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            pixmap->show();
            pixmap->setStyleSheet("background-color: none;");
            _width += pixmap->width();
            layout->addWidget(pixmap);
        }
        else if(stringList.at(i).contains("QTextEdit("))
        {
            QLineEdit* tE = new QLineEdit(this);
            tE->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            tE->setFixedSize(20, 15);
            tE->setFont(QFont("Courier", 5));
            _width += tE->width();
            layout->addWidget(tE);
        } else
        {
            QLabel* text = new QLabel(stringList.at(i), this);
            text->setStyleSheet("background-color: none;");
            text->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            text->show();
            _width += text->width();
            layout->addWidget(text);
        }
    }
    setLayout(layout);
    raise();

    setFixedSize(_width+20, 28);
    hide();
}

DragableElement::~DragableElement()
{

}

void DragableElement::setScriptAreaWidget(QWidget* scriptAreaWidget)
{
    _scriptAreaWidget = scriptAreaWidget;
}

void DragableElement::mousePressEvent(QMouseEvent* event)
{
    _offset = event->pos();
    if(!_dragged)
    {
        DragableElement* element = new DragableElement(_text, _color, _scriptAreaWidget, QApplication::activeWindow());
        element->_dragged = true;
        element->setFixedHeight(height());
        element->setFixedWidth(width());
        element->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        element->grabMouse();
    }
}

void DragableElement::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(mapToParent(event->pos() - _offset));
        show();
    }
}

void DragableElement::mouseReleaseEvent(QMouseEvent* event)
{
    releaseMouse();
    QRect scriptArea = QRect(_scriptAreaWidget->mapToGlobal(QPoint(0,0)), QSize(_scriptAreaWidget->width(), _scriptAreaWidget->height()));
    if(!scriptArea.contains(QRect(mapToGlobal(QPoint(0, 0)), QSize(width(), height())), true))
    {
        delete this;
    }
}

void DragableElement::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    QPolygon poly;

    poly << QPoint(0, 0) << QPoint(7, 0)
         << QPoint(11, 4) << QPoint(21, 4)
         << QPoint(25, 0) << QPoint(_width+20, 0)
         << QPoint(_width+20, 20) << QPoint(23, 20)
         << QPoint(21, 24) << QPoint(11, 24)
         << QPoint(7, 20) << QPoint(0, 20)
         << QPoint(0, 0);

    // style(), width(), brush(), capStyle() and joinStyle().
    QPen pen(QColor(_color), 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(pen);

    // Brush
    QBrush brush;
    brush.setColor(QColor(_color));
    brush.setStyle(Qt::SolidPattern);

    // Fill polygon
    QPainterPath path;
    path.addPolygon(poly);

    // Draw polygon
    painter.drawPolygon(poly);
    painter.fillPath(path, brush);
    painter.setBackgroundMode(Qt::TransparentMode);
}
