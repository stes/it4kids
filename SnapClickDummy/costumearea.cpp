#include "costumearea.h"

CostumeArea::CostumeArea(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("background-color: #474747");
    setMinimumSize(200, 200);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _layout = new QHBoxLayout();
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    _costumeListWidget = new QWidget(this);
    _costumeListWidget->setFixedWidth(95);
    _layout->addWidget(_costumeListWidget);

    _costumeListLayout = new QVBoxLayout(this);
    _costumeListLayout->setAlignment(Qt::AlignTop);
    _costumeListLayout->setContentsMargins(0, 0, 0, 0);
    _costumeListLayout->setSpacing(5);
    _costumeListWidget->setLayout(_costumeListLayout);

    _newCostume = new QLabel("Neues Kostüm", this);
    _newCostume->setFixedWidth(95);
    _newCostume->setAlignment(Qt::AlignCenter);
    _newCostume->setStyleSheet("color: #ffffff; font-weight: bold;");
    _costumeListLayout->addWidget(_newCostume);
    QPushButton* newCostumeButton = new QPushButton(this);
    newCostumeButton->setFixedSize(95, 24);
    newCostumeButton->setStyleSheet("background-image: url(:/snap/Resources/newCostume.png); background-repeat: none; margin-left: 26px;");
    _costumeListLayout->addWidget(newCostumeButton);
    _costume = new QLabel("<html><img src=':/snap/Resources/TurtleSprite.png'><p align='center' >TestSprite</p></html>");
    _costume->setStyleSheet("color: #ffffff; margin-left: 5px;");
    _costumeListLayout->addWidget(_costume);

    _drawingArea = new QLabel(this);
    _drawingArea->setStyleSheet("background-color: #ffffff");
    _drawingArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _layout->addWidget(_drawingArea);

    setLayout(_layout);
}

CostumeArea::~CostumeArea()
{

}


