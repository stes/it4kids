#include "snapelement.h"
#include <qdebug.h>

#include <QBitmap>
#include <QGraphicsColorizeEffect>
#include <QPixmap>
#include <QHBoxLayout>

SnapElement::SnapElement(const QString &text, const QColor &color, const QString& maskPath, QWidget *parent) :
    QLabel(parent), _text(text), _color(color), _maskPath(maskPath), _dragged(false)
{
    QLabel* content = new QLabel(this);
    content->setStyleSheet("background-color: none;");

    QHBoxLayout* layout = new QHBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
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
            pixmap->setPixmap(QPixmap(pixmapPath));
            pixmap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            pixmap->show();
            pixmap->setStyleSheet("background-color: none;");
            _width += pixmap->width();
            layout->addWidget(pixmap);
        } else {
            QLabel* text = new QLabel(stringList.at(i), this);
            text->setStyleSheet("background-color: none;");
            text->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            text->show();
            _width += text->width();
            qDebug() << text->width();
            layout->addWidget(text);
        }
    }
    setLayout(layout);
    raise();

    setFixedSize(_width+20, 28);
    hide();
}

SnapElement::~SnapElement()
{

}

void SnapElement::mousePressEvent(QMouseEvent* event)
{
    _offset = event->pos();
    if(!_dragged)
    {
        SnapElement* element = new SnapElement(_text, _color, _maskPath, QApplication::activeWindow());
        element->_dragged = true;
        element->setFixedHeight(height());
        element->setFixedWidth(width());
        element->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        element->grabMouse();
    }
}

void SnapElement::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(mapToParent(event->pos() - _offset));
        show();
    }
}

void SnapElement::mouseReleaseEvent(QMouseEvent *event)
{
    releaseMouse();
    if((event->globalPos().x() < 260 || event->globalPos().x() > 1380) || event->globalPos().y() < 145)
    {
        delete this;
    }
}

void SnapElement::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

        QPolygon poly;

        poly << QPoint(0, 0) << QPoint(7, 0)
             << QPoint(11, 4) << QPoint(21, 4)
             << QPoint(25, 0) << QPoint(_width+20, 0)
             << QPoint(_width+20, 20) << QPoint(23, 20)
             << QPoint(21, 24) << QPoint(11, 24)\
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
