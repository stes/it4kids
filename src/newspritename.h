#ifndef NEWSPRITENAME_H
#define NEWSPRITENAME_H

#include <QDialog>

namespace Ui {
class NewSpriteName;
}

class NewSpriteName : public QDialog
{
    Q_OBJECT

public:
    explicit NewSpriteName(QWidget *parent = 0);
    QString getName();
    ~NewSpriteName();

private:
    Ui::NewSpriteName *ui;
};

#endif // NEWSPRITENAME_H
