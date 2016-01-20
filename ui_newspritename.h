/********************************************************************************
** Form generated from reading UI file 'newspritename.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSPRITENAME_H
#define UI_NEWSPRITENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewSpriteName
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewSpriteName)
    {
        if (NewSpriteName->objectName().isEmpty())
            NewSpriteName->setObjectName(QStringLiteral("NewSpriteName"));
        NewSpriteName->resize(400, 86);
        verticalLayout = new QVBoxLayout(NewSpriteName);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(NewSpriteName);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(NewSpriteName);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout->addWidget(nameEdit);

        buttonBox = new QDialogButtonBox(NewSpriteName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewSpriteName);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewSpriteName, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewSpriteName, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewSpriteName);
    } // setupUi

    void retranslateUi(QDialog *NewSpriteName)
    {
        NewSpriteName->setWindowTitle(QApplication::translate("NewSpriteName", "Dialog", 0));
        label->setText(QApplication::translate("NewSpriteName", "Bitte Namen f\303\274r neue Figur eingeben", 0));
    } // retranslateUi

};

namespace Ui {
    class NewSpriteName: public Ui_NewSpriteName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSPRITENAME_H
