#ifndef FIGURE_H
#define FIGURE_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

class DragableElement;
class DockingArea;
class QImage;
class ScriptArea;

typedef std::vector<DockingArea*> HitTestVector;
typedef std::vector<DragableElement*> DragElemVector;
typedef std::vector<QImage*> CostumeVector;

class Sprite : public QWidget
{
    friend class ScriptArea;
    Q_OBJECT
public:
    explicit Sprite(ScriptArea* scriptArea, const QString& name = "Sprite", QWidget *parent = 0);

private:
    void mousePressEvent(QMouseEvent*);

    QString _name;
    CostumeVector _costumeVector;
    QLabel _imageLabel;
    QLabel _label;
    QVBoxLayout _layout;

    HitTestVector _hitTestVector;
    DragElemVector _dragElemVector;

    ScriptArea* _scriptArea;
};

#endif // FIGURE_H
