#ifndef COSTUMEAREA
#define COSTUMEAREA

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "snaproundbutton.h"

class CostumeArea : public QWidget
{
    Q_OBJECT
public:
    CostumeArea(QWidget* parent = 0);
    ~CostumeArea();
protected:
    QHBoxLayout* _layout;

    QWidget* _costumeListWidget;
    QVBoxLayout* _costumeListLayout;

    QLabel* _newCostume;
    SnapRoundButton* _newCostumeButton;

    QLabel* _costume;
    QLabel* _drawingArea;
};

#endif // COSTUMEAREA

