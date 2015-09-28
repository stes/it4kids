/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <categoryselect.h>
#include <dragelemlist.h>
#include <scene.h>
#include <scriptarea.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *upperSceneFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonFullScreen;
    QLineEdit *lineEdit;
    QPushButton *buttonScriptStart;
    QPushButton *buttonStopScript;
    Scene *widget;
    QLabel *labelCoordinates;
    QFrame *selectionFrame;
    QGridLayout *gridLayout;
    QWidget *selectionSprite;
    QWidget *selectionBackground;
    QFrame *upperSpriteFrame;
    QFrame *selectionPaddingFrame;
    QTabWidget *centerAreaWidget;
    QWidget *tabScript;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    CategorySelect *categorySelect;
    DragElemList *elementList;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    ScriptArea *scriptArea;
    QWidget *tabCostume;
    QWidget *tabSound;
    QFrame *frame_31;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonFile;
    QPushButton *buttonEdit;
    QPushButton *buttonHints;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonMinimize;
    QPushButton *buttonClose;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(953, 546);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, -1);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        upperSceneFrame = new QFrame(frame);
        upperSceneFrame->setObjectName(QStringLiteral("upperSceneFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upperSceneFrame->sizePolicy().hasHeightForWidth());
        upperSceneFrame->setSizePolicy(sizePolicy);
        upperSceneFrame->setMinimumSize(QSize(482, 30));
        upperSceneFrame->setFrameShape(QFrame::StyledPanel);
        upperSceneFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(upperSceneFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        buttonFullScreen = new QPushButton(upperSceneFrame);
        buttonFullScreen->setObjectName(QStringLiteral("buttonFullScreen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Assets/fullScreenOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/Assets/fullScreenOff.png"), QSize(), QIcon::Normal, QIcon::On);
        buttonFullScreen->setIcon(icon);
        buttonFullScreen->setFlat(true);

        horizontalLayout_2->addWidget(buttonFullScreen);

        lineEdit = new QLineEdit(upperSceneFrame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        buttonScriptStart = new QPushButton(upperSceneFrame);
        buttonScriptStart->setObjectName(QStringLiteral("buttonScriptStart"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Assets/greenFlagOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonScriptStart->setIcon(icon1);
        buttonScriptStart->setFlat(true);

        horizontalLayout_2->addWidget(buttonScriptStart);

        buttonStopScript = new QPushButton(upperSceneFrame);
        buttonStopScript->setObjectName(QStringLiteral("buttonStopScript"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../scratch-flash/src/assets/UI/buttons/stopOn.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStopScript->setIcon(icon2);
        buttonStopScript->setFlat(true);

        horizontalLayout_2->addWidget(buttonStopScript);


        verticalLayout->addWidget(upperSceneFrame);

        widget = new Scene(frame);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(482, 360));

        verticalLayout->addWidget(widget);

        labelCoordinates = new QLabel(frame);
        labelCoordinates->setObjectName(QStringLiteral("labelCoordinates"));
        sizePolicy.setHeightForWidth(labelCoordinates->sizePolicy().hasHeightForWidth());
        labelCoordinates->setSizePolicy(sizePolicy);
        labelCoordinates->setMinimumSize(QSize(482, 18));

        verticalLayout->addWidget(labelCoordinates);

        selectionFrame = new QFrame(frame);
        selectionFrame->setObjectName(QStringLiteral("selectionFrame"));
        selectionFrame->setFrameShape(QFrame::StyledPanel);
        selectionFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(selectionFrame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        selectionSprite = new QWidget(selectionFrame);
        selectionSprite->setObjectName(QStringLiteral("selectionSprite"));

        gridLayout->addWidget(selectionSprite, 1, 1, 1, 1);

        selectionBackground = new QWidget(selectionFrame);
        selectionBackground->setObjectName(QStringLiteral("selectionBackground"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectionBackground->sizePolicy().hasHeightForWidth());
        selectionBackground->setSizePolicy(sizePolicy1);
        selectionBackground->setMinimumSize(QSize(75, 0));

        gridLayout->addWidget(selectionBackground, 1, 0, 1, 1);

        upperSpriteFrame = new QFrame(selectionFrame);
        upperSpriteFrame->setObjectName(QStringLiteral("upperSpriteFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(upperSpriteFrame->sizePolicy().hasHeightForWidth());
        upperSpriteFrame->setSizePolicy(sizePolicy2);
        upperSpriteFrame->setMinimumSize(QSize(0, 40));
        upperSpriteFrame->setFrameShape(QFrame::StyledPanel);
        upperSpriteFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(upperSpriteFrame, 0, 1, 1, 1);

        selectionPaddingFrame = new QFrame(selectionFrame);
        selectionPaddingFrame->setObjectName(QStringLiteral("selectionPaddingFrame"));
        sizePolicy2.setHeightForWidth(selectionPaddingFrame->sizePolicy().hasHeightForWidth());
        selectionPaddingFrame->setSizePolicy(sizePolicy2);
        selectionPaddingFrame->setMinimumSize(QSize(0, 40));
        selectionPaddingFrame->setFrameShape(QFrame::StyledPanel);
        selectionPaddingFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(selectionPaddingFrame, 0, 0, 1, 1);


        verticalLayout->addWidget(selectionFrame);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        centerAreaWidget = new QTabWidget(centralWidget);
        centerAreaWidget->setObjectName(QStringLiteral("centerAreaWidget"));
        centerAreaWidget->setMinimumSize(QSize(200, 0));
        centerAreaWidget->setTabBarAutoHide(false);
        tabScript = new QWidget();
        tabScript->setObjectName(QStringLiteral("tabScript"));
        horizontalLayout_3 = new QHBoxLayout(tabScript);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 0, 0);
        frame_3 = new QFrame(tabScript);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        categorySelect = new CategorySelect(frame_3);
        categorySelect->setObjectName(QStringLiteral("categorySelect"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(categorySelect->sizePolicy().hasHeightForWidth());
        categorySelect->setSizePolicy(sizePolicy3);
        categorySelect->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(categorySelect);

        elementList = new DragElemList(frame_3);
        elementList->setObjectName(QStringLiteral("elementList"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(elementList->sizePolicy().hasHeightForWidth());
        elementList->setSizePolicy(sizePolicy4);
        elementList->setMinimumSize(QSize(200, 50));

        verticalLayout_2->addWidget(elementList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(frame_3);

        widget_2 = new QWidget(tabScript);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scriptArea = new ScriptArea(widget_2);
        scriptArea->setObjectName(QStringLiteral("scriptArea"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scriptArea->sizePolicy().hasHeightForWidth());
        scriptArea->setSizePolicy(sizePolicy5);
        scriptArea->setMinimumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(scriptArea);


        horizontalLayout_3->addWidget(widget_2);

        centerAreaWidget->addTab(tabScript, QString());
        tabCostume = new QWidget();
        tabCostume->setObjectName(QStringLiteral("tabCostume"));
        centerAreaWidget->addTab(tabCostume, QString());
        tabSound = new QWidget();
        tabSound->setObjectName(QStringLiteral("tabSound"));
        centerAreaWidget->addTab(tabSound, QString());

        gridLayout_2->addWidget(centerAreaWidget, 1, 1, 1, 1);

        frame_31 = new QFrame(centralWidget);
        frame_31->setObjectName(QStringLiteral("frame_31"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frame_31->sizePolicy().hasHeightForWidth());
        frame_31->setSizePolicy(sizePolicy6);
        frame_31->setMinimumSize(QSize(0, 23));
        frame_31->setStyleSheet(QStringLiteral("background-color: #9c9ea2;"));
        horizontalLayout = new QHBoxLayout(frame_31);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonFile = new QPushButton(frame_31);
        buttonFile->setObjectName(QStringLiteral("buttonFile"));
        sizePolicy4.setHeightForWidth(buttonFile->sizePolicy().hasHeightForWidth());
        buttonFile->setSizePolicy(sizePolicy4);
        buttonFile->setMinimumSize(QSize(0, 20));
        buttonFile->setFlat(true);

        horizontalLayout->addWidget(buttonFile);

        buttonEdit = new QPushButton(frame_31);
        buttonEdit->setObjectName(QStringLiteral("buttonEdit"));
        sizePolicy4.setHeightForWidth(buttonEdit->sizePolicy().hasHeightForWidth());
        buttonEdit->setSizePolicy(sizePolicy4);
        buttonEdit->setMinimumSize(QSize(0, 20));
        buttonEdit->setFlat(true);

        horizontalLayout->addWidget(buttonEdit);

        buttonHints = new QPushButton(frame_31);
        buttonHints->setObjectName(QStringLiteral("buttonHints"));
        sizePolicy2.setHeightForWidth(buttonHints->sizePolicy().hasHeightForWidth());
        buttonHints->setSizePolicy(sizePolicy2);
        buttonHints->setMinimumSize(QSize(0, 20));
        buttonHints->setFlat(true);

        horizontalLayout->addWidget(buttonHints);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonMinimize = new QPushButton(frame_31);
        buttonMinimize->setObjectName(QStringLiteral("buttonMinimize"));
        buttonMinimize->setMinimumSize(QSize(0, 20));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Assets/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMinimize->setIcon(icon3);
        buttonMinimize->setFlat(true);

        horizontalLayout->addWidget(buttonMinimize);

        buttonClose = new QPushButton(frame_31);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setMinimumSize(QSize(0, 20));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Assets/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonClose->setIcon(icon4);
        buttonClose->setFlat(true);

        horizontalLayout->addWidget(buttonClose);


        gridLayout_2->addWidget(frame_31, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(buttonClose, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(buttonMinimize, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));

        centerAreaWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        buttonFullScreen->setText(QString());
        buttonScriptStart->setText(QString());
        buttonStopScript->setText(QString());
        labelCoordinates->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabScript), QApplication::translate("MainWindow", "Skripte", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabCostume), QApplication::translate("MainWindow", "Kost\303\274me", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabSound), QApplication::translate("MainWindow", "Kl\303\244nge", 0));
        buttonFile->setText(QApplication::translate("MainWindow", "Datei", 0));
        buttonEdit->setText(QApplication::translate("MainWindow", "Bearbeiten", 0));
        buttonHints->setText(QApplication::translate("MainWindow", "Tipps", 0));
        buttonMinimize->setText(QString());
        buttonClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
