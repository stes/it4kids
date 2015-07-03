#include "snapelementwidget.h"
#include <QMainWindow>
#include <QDebug>

SnapElementWidget::SnapElementWidget(QWidget* parent) :
    QLabel(parent), _currentActiveCategory(0), _snapElementCount(0)
{
    setStyleSheet("SnapElementWidget {background-color: #373737; border: none; border-right: 4px solid #272727;}");
    _mainLayout = new QGridLayout(this);

    _categoryLayout = new QGridLayout(this);
    QLabel* categorySpace = new QLabel(this);
    categorySpace->setObjectName("categorySpace");
    categorySpace->setStyleSheet("QLabel#categorySpace {background-color: #474747; border: none;}");
    categorySpace->setMinimumSize(196, 100);
    categorySpace->setLayout(_categoryLayout);

    _mainLayout->addWidget(categorySpace, 0, 0, 1, 2);
    _mainLayout->setAlignment(Qt::AlignTop);
    _mainLayout->setContentsMargins(0, 0, 0, 0);

    SnapElementCategory* categoryMotion = new SnapElementCategory("Bewegung", "#7f94d2", this);
    connect(categoryMotion, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    SnapElement* se = new SnapElement("bla bli blub und bloerg", "#7f94d2", this);
    categoryMotion->addSnapElement(se);
    _categoryLayout->addWidget(categoryMotion, 0, 0);

    SnapElementCategory* categoryControl = new SnapElementCategory("Steuerung", "#ddb867", this);
    connect(categoryControl, SIGNAL(CategoryChange(SnapElementCategory*)), this, SLOT(ChangeVisibleCategory(SnapElementCategory*)));
    SnapElement* se2 = new SnapElement("bla bli blub und blaerg", "#ddb867", this);
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

    _categoryLayout->setContentsMargins(12, 5, 4, 9);

    setLayout(_mainLayout);
    setFixedWidth(200);
}

SnapElementWidget::~SnapElementWidget()
{

}

void SnapElementWidget::ChangeVisibleCategory(SnapElementCategory* category)
{
    if(_currentActiveCategory != 0) _currentActiveCategory->ToggleActive();
    _currentActiveCategory = category;
    qDebug() << _mainLayout->rowCount();
    for(int i = 1; i < _snapElementCount+1; i++)
    {
        _mainLayout->itemAtPosition(i, 0)->widget()->hide();
        _mainLayout->removeItem(_mainLayout->itemAtPosition(i, 0));
        delete _mainLayout->itemAtPosition(i, 1)->widget();
        _mainLayout->removeItem(_mainLayout->itemAtPosition(i, 1));
    }
    _snapElementCount =  category->getSnapElementList()->size();
    for(int i = 0; i < category->getSnapElementList()->size(); i++)
    {
        _mainLayout->addWidget(category->getSnapElementList()->at(i), i+1, 0, 1, 1);
        QSpacerItem* spacer = new QSpacerItem(0,0, QSizePolicy::Expanding);
        _mainLayout->addItem(spacer, i+1, 1, 1, 1);
        category->getSnapElementList()->at(i)->show();
    }
}
