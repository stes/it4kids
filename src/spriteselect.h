#ifndef SPRITESELECT_H
#define SPRITESELECT_H

#include <vector>

#include <QGridLayout>
#include <QWidget>

class SpriteModel;

class SpriteSelect : public QWidget
{
    Q_OBJECT
public:
    SpriteSelect(QWidget* parent = 0);
    ~SpriteSelect();

    void setSpriteModel(const SpriteModel *model);

private slots:
    void updateSprites();

private:
    const SpriteModel* _spriteModel;

    QGridLayout _layout;
};

#endif // SPRITESELECT_H
