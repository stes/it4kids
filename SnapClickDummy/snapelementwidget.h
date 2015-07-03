#ifndef SNAPELEMENTLIST
#define SNAPELEMENTLIST

#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSpacerItem>

#include <QtGui>
#include <QByteArray>
#include <QDataStream>
#include <QDrag>

#include "snapelementcategory.h"
#include "snapelement.h"

class SnapElementWidget : public QLabel
{
    Q_OBJECT

public:
    SnapElementWidget(QWidget* parent = 0);
    ~SnapElementWidget();

public slots:
    void ChangeVisibleCategory(SnapElementCategory* category);

protected:
    QGridLayout* _mainLayout;
    QGridLayout* _categoryLayout;

    SnapElementCategory* _currentActiveCategory;
    int _snapElementCount;
};



#endif // SNAPELEMENTLIST

