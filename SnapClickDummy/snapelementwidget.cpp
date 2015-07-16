#include "snapelementwidget.h"
#include <QMainWindow>
#include <QDebug>

SnapElementWidget::SnapElementWidget(QWidget* parent) :
    QLabel(parent), _currentActiveCategory(0)
{
    _categoryLayout = new QGridLayout(this);
    QLabel* categorySpace = new QLabel(this);
    categorySpace->setObjectName("categorySpace");
    categorySpace->setLayout(_categoryLayout);

    SnapElementCategory* categoryMotion = new SnapElementCategory("Bewegung", "#7f94d2", this);
    connect(categoryMotion, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    SnapElement* se = new SnapElement("gehe Schritte", QColor(74, 108, 212), ":snap/Resources/midsnapelement.png", this);
    SnapElement* se1 = new SnapElement("drehe Grad", QColor(74, 108, 212), ":snap/Resources/midsnapelement.png", this);
    categoryMotion->addSnapElement(se);
    categoryMotion->addSnapElement(se1);
    _categoryLayout->addWidget(categoryMotion, 0, 0);

    SnapElementCategory* categoryControl = new SnapElementCategory("Steuerung", "#ddb867", this);
    connect(categoryControl, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    SnapElement* se2 = new SnapElement("Wenn *QPixmap(:snap/Resources/startscripticon.png)* angeklickt", QColor(230, 168, 34), ":snap/Resources/topsnapelement.png", this);
    categoryControl->addSnapElement(se2);
    _categoryLayout->addWidget(categoryControl, 0, 1);

    SnapElementCategory* categoryLook = new SnapElementCategory("Aussehen", "#a987db", this);
    connect(categoryLook, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    _categoryLayout->addWidget(categoryLook, 1, 0);

    SnapElementCategory* categoryFeel = new SnapElementCategory("Fuehlen", "#55a6cf", this);
    connect(categoryFeel, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    _categoryLayout->addWidget(categoryFeel, 1, 1);

    SnapElementCategory* categorySound = new SnapElementCategory("Klang", "#cf7fd5", this);
    connect(categorySound, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    _categoryLayout->addWidget(categorySound, 2, 0);

    SnapElementCategory* categoryOperators = new SnapElementCategory("Operatoren", "#8ac05d", this);
    connect(categoryOperators, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    _categoryLayout->addWidget(categoryOperators, 2, 1);

    SnapElementCategory* categoryPen = new SnapElementCategory("Stift", "#53b49b", this);
    connect(categoryPen, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    _categoryLayout->addWidget(categoryPen, 3, 0);

    SnapElementCategory* categoryVariables = new SnapElementCategory("Variablen", "#e59a64", this);
    connect(categoryVariables, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    _categoryLayout->addWidget(categoryVariables, 3, 1);

    _categoryLayout->setContentsMargins(12, 5, 4, 0);
}

SnapElementWidget::~SnapElementWidget()
{

}

void SnapElementWidget::ChangeVisibleCategory(SnapElementCategory* category)
{
    if(_currentActiveCategory != 0)
    {
        _currentActiveCategory->ToggleActive();
        for(int i = 0; i < _currentActiveCategory->getSnapElementList()->size(); i++)
        {
            _currentActiveCategory->getSnapElementList()->at(i)->hide();
        }
    }
    _currentActiveCategory = category;
    for(int i = 0; i < category->getSnapElementList()->size(); i++)
    {
        category->getSnapElementList()->at(i)->show();
        category->getSnapElementList()->at(i)->move(0, 120+i*40);
    }
}
