#ifndef CENTERAREA
#define CENTERAREA

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QCheckBox>
#include <QTabWidget>
#include <QSpacerItem>

#include "scriptarea.h"
#include "costumearea.h"
#include "soundarea.h"

class CenterArea : public QWidget
{
    Q_OBJECT
public:
    CenterArea(QWidget* parent = 0);
    ~CenterArea();
private:
    QGridLayout* _layout;
    QPushButton* _freelyRotatable;
    QPushButton* _leftrightRotatable;
    QPushButton* _nonRotatable;
    QLabel* _activeSprite;
    QTextEdit* _spriteName;
    QCheckBox* _draggable;
    QTabWidget* _centerTab;
};

#endif // CENTERAREA

