#ifndef SNAPELEMENTSCATEGORY
#define SNAPELEMENTSCATEGORY

#include <QPushButton>
#include <vector>

#include "snapelement.h"

typedef std::vector<SnapElement*> SnapElementList;

class SnapElementCategory : public QPushButton
{
    Q_OBJECT

public:
    SnapElementCategory(const QString& text, const QString& color, QWidget* parent = 0);
    ~SnapElementCategory();

    inline SnapElementList* getSnapElementList() {return &_snapElementList;}
    inline void addSnapElement(SnapElement* element) {_snapElementList.push_back(element);}

public slots:
    void ToggleActive();

signals:
    void CategoryChange(SnapElementCategory* elementList);

protected:
    bool _active;
    QString _color;
    SnapElementList _snapElementList;
};

#endif // SNAPELEMENTSCATEGORY

