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
#include <spriteselect.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *centerAreaWidget;
    QWidget *tabScript;
    QHBoxLayout *horizontalLayout_3;
    QFrame *CategorySelectFrame;
    QVBoxLayout *verticalLayout_2;
    CategorySelect *categorySelect;
    DragElemList *elementList;
    ScriptArea *scriptArea;
    QHBoxLayout *horizontalLayout_4;
    QWidget *tabCostume;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *NewCostume;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *widget;
    QFrame *frame_2;
    QWidget *tabSound;
    QFrame *leftAreaFrame;
    QVBoxLayout *verticalLayout;
    QFrame *upperSceneFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonFullScreen;
    QLineEdit *lineEdit;
    QPushButton *buttonScriptStart;
    QPushButton *buttonStopScript;
    Scene *scene;
    QFrame *selectionFrame;
    QGridLayout *gridLayout;
    SpriteSelect *spriteSelect;
    QWidget *selectionBackground;
    QFrame *upperSpriteFrame;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QFrame *selectionPaddingFrame;
    QFrame *toolBarFrame;
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
        horizontalLayout_3->setContentsMargins(0, 5, 0, 0);
        CategorySelectFrame = new QFrame(tabScript);
        CategorySelectFrame->setObjectName(QStringLiteral("CategorySelectFrame"));
        CategorySelectFrame->setFrameShape(QFrame::StyledPanel);
        CategorySelectFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(CategorySelectFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        categorySelect = new CategorySelect(CategorySelectFrame);
        categorySelect->setObjectName(QStringLiteral("categorySelect"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(categorySelect->sizePolicy().hasHeightForWidth());
        categorySelect->setSizePolicy(sizePolicy);
        categorySelect->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(categorySelect);

        elementList = new DragElemList(CategorySelectFrame);
        elementList->setObjectName(QStringLiteral("elementList"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(elementList->sizePolicy().hasHeightForWidth());
        elementList->setSizePolicy(sizePolicy1);
        elementList->setMinimumSize(QSize(200, 50));

        verticalLayout_2->addWidget(elementList);


        horizontalLayout_3->addWidget(CategorySelectFrame);

        scriptArea = new ScriptArea(tabScript);
        scriptArea->setObjectName(QStringLiteral("scriptArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scriptArea->sizePolicy().hasHeightForWidth());
        scriptArea->setSizePolicy(sizePolicy2);
        horizontalLayout_4 = new QHBoxLayout(scriptArea);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_3->addWidget(scriptArea);

        centerAreaWidget->addTab(tabScript, QString());
        tabCostume = new QWidget();
        tabCostume->setObjectName(QStringLiteral("tabCostume"));
        horizontalLayout_5 = new QHBoxLayout(tabCostume);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frame = new QFrame(tabCostume);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        NewCostume = new QLabel(frame);
        NewCostume->setObjectName(QStringLiteral("NewCostume"));
        NewCostume->setStyleSheet(QLatin1String("font-weight: bold;\n"
"color: #5c5d5f;"));
        NewCostume->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(NewCostume);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_3);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Assets/libraryOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setFlat(true);

        horizontalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Assets/paintbrushOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setFlat(true);

        horizontalLayout_6->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Assets/importOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setFlat(true);

        horizontalLayout_6->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(frame_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy3.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy3);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Assets/landscapeOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setFlat(true);

        horizontalLayout_6->addWidget(pushButton_4);


        verticalLayout_3->addWidget(frame_3);

        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(widget);


        horizontalLayout_5->addWidget(frame);

        frame_2 = new QFrame(tabCostume);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frame_2);

        centerAreaWidget->addTab(tabCostume, QString());
        tabSound = new QWidget();
        tabSound->setObjectName(QStringLiteral("tabSound"));
        centerAreaWidget->addTab(tabSound, QString());

        gridLayout_2->addWidget(centerAreaWidget, 1, 1, 1, 1);

        leftAreaFrame = new QFrame(centralWidget);
        leftAreaFrame->setObjectName(QStringLiteral("leftAreaFrame"));
        leftAreaFrame->setFrameShape(QFrame::StyledPanel);
        leftAreaFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(leftAreaFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        upperSceneFrame = new QFrame(leftAreaFrame);
        upperSceneFrame->setObjectName(QStringLiteral("upperSceneFrame"));
        sizePolicy3.setHeightForWidth(upperSceneFrame->sizePolicy().hasHeightForWidth());
        upperSceneFrame->setSizePolicy(sizePolicy3);
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
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Assets/fullScreenOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/Assets/fullScreenOff.png"), QSize(), QIcon::Normal, QIcon::On);
        buttonFullScreen->setIcon(icon4);
        buttonFullScreen->setFlat(true);

        horizontalLayout_2->addWidget(buttonFullScreen);

        lineEdit = new QLineEdit(upperSceneFrame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        buttonScriptStart = new QPushButton(upperSceneFrame);
        buttonScriptStart->setObjectName(QStringLiteral("buttonScriptStart"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Assets/greenFlagOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonScriptStart->setIcon(icon5);
        buttonScriptStart->setFlat(true);

        horizontalLayout_2->addWidget(buttonScriptStart);

        buttonStopScript = new QPushButton(upperSceneFrame);
        buttonStopScript->setObjectName(QStringLiteral("buttonStopScript"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../scratch-flash/src/assets/UI/buttons/stopOn.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStopScript->setIcon(icon6);
        buttonStopScript->setFlat(true);

        horizontalLayout_2->addWidget(buttonStopScript);


        verticalLayout->addWidget(upperSceneFrame);

        scene = new Scene(leftAreaFrame);
        scene->setObjectName(QStringLiteral("scene"));
        sizePolicy3.setHeightForWidth(scene->sizePolicy().hasHeightForWidth());
        scene->setSizePolicy(sizePolicy3);
        scene->setMinimumSize(QSize(482, 360));

        verticalLayout->addWidget(scene);

        selectionFrame = new QFrame(leftAreaFrame);
        selectionFrame->setObjectName(QStringLiteral("selectionFrame"));
        sizePolicy.setHeightForWidth(selectionFrame->sizePolicy().hasHeightForWidth());
        selectionFrame->setSizePolicy(sizePolicy);
        selectionFrame->setMinimumSize(QSize(482, 0));
        selectionFrame->setFrameShape(QFrame::StyledPanel);
        selectionFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(selectionFrame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spriteSelect = new SpriteSelect(selectionFrame);
        spriteSelect->setObjectName(QStringLiteral("spriteSelect"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(spriteSelect->sizePolicy().hasHeightForWidth());
        spriteSelect->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(spriteSelect, 1, 1, 1, 1);

        selectionBackground = new QWidget(selectionFrame);
        selectionBackground->setObjectName(QStringLiteral("selectionBackground"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(selectionBackground->sizePolicy().hasHeightForWidth());
        selectionBackground->setSizePolicy(sizePolicy6);
        selectionBackground->setMinimumSize(QSize(75, 0));

        gridLayout->addWidget(selectionBackground, 1, 0, 1, 1);

        upperSpriteFrame = new QFrame(selectionFrame);
        upperSpriteFrame->setObjectName(QStringLiteral("upperSpriteFrame"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(upperSpriteFrame->sizePolicy().hasHeightForWidth());
        upperSpriteFrame->setSizePolicy(sizePolicy7);
        upperSpriteFrame->setMinimumSize(QSize(0, 40));
        upperSpriteFrame->setFrameShape(QFrame::StyledPanel);
        upperSpriteFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(upperSpriteFrame);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(10, 0, 2, 0);
        label_2 = new QLabel(upperSpriteFrame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label = new QLabel(upperSpriteFrame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        pushButton_7 = new QPushButton(upperSpriteFrame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy3.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy3);
        pushButton_7->setStyleSheet(QStringLiteral(""));
        pushButton_7->setIcon(icon);
        pushButton_7->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(upperSpriteFrame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy3.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy3);
        pushButton_6->setIcon(icon1);
        pushButton_6->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(upperSpriteFrame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);
        pushButton_5->setIcon(icon2);
        pushButton_5->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(upperSpriteFrame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy3.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy3);
        pushButton_8->setIcon(icon3);
        pushButton_8->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_8);


        gridLayout->addWidget(upperSpriteFrame, 0, 1, 1, 1);

        selectionPaddingFrame = new QFrame(selectionFrame);
        selectionPaddingFrame->setObjectName(QStringLiteral("selectionPaddingFrame"));
        sizePolicy7.setHeightForWidth(selectionPaddingFrame->sizePolicy().hasHeightForWidth());
        selectionPaddingFrame->setSizePolicy(sizePolicy7);
        selectionPaddingFrame->setMinimumSize(QSize(0, 40));
        selectionPaddingFrame->setFrameShape(QFrame::StyledPanel);
        selectionPaddingFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(selectionPaddingFrame, 0, 0, 1, 1);


        verticalLayout->addWidget(selectionFrame);


        gridLayout_2->addWidget(leftAreaFrame, 1, 0, 1, 1);

        toolBarFrame = new QFrame(centralWidget);
        toolBarFrame->setObjectName(QStringLiteral("toolBarFrame"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(toolBarFrame->sizePolicy().hasHeightForWidth());
        toolBarFrame->setSizePolicy(sizePolicy8);
        toolBarFrame->setMinimumSize(QSize(0, 23));
        toolBarFrame->setStyleSheet(QStringLiteral("background-color: #9c9ea2;"));
        horizontalLayout = new QHBoxLayout(toolBarFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonFile = new QPushButton(toolBarFrame);
        buttonFile->setObjectName(QStringLiteral("buttonFile"));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(buttonFile->sizePolicy().hasHeightForWidth());
        buttonFile->setSizePolicy(sizePolicy9);
        buttonFile->setMinimumSize(QSize(0, 20));
        buttonFile->setFlat(true);

        horizontalLayout->addWidget(buttonFile);

        buttonEdit = new QPushButton(toolBarFrame);
        buttonEdit->setObjectName(QStringLiteral("buttonEdit"));
        sizePolicy9.setHeightForWidth(buttonEdit->sizePolicy().hasHeightForWidth());
        buttonEdit->setSizePolicy(sizePolicy9);
        buttonEdit->setMinimumSize(QSize(0, 20));
        buttonEdit->setFlat(true);

        horizontalLayout->addWidget(buttonEdit);

        buttonHints = new QPushButton(toolBarFrame);
        buttonHints->setObjectName(QStringLiteral("buttonHints"));
        sizePolicy7.setHeightForWidth(buttonHints->sizePolicy().hasHeightForWidth());
        buttonHints->setSizePolicy(sizePolicy7);
        buttonHints->setMinimumSize(QSize(0, 20));
        buttonHints->setFlat(true);

        horizontalLayout->addWidget(buttonHints);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonMinimize = new QPushButton(toolBarFrame);
        buttonMinimize->setObjectName(QStringLiteral("buttonMinimize"));
        buttonMinimize->setMinimumSize(QSize(0, 20));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Assets/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMinimize->setIcon(icon7);
        buttonMinimize->setFlat(true);

        horizontalLayout->addWidget(buttonMinimize);

        buttonClose = new QPushButton(toolBarFrame);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setMinimumSize(QSize(0, 20));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Assets/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonClose->setIcon(icon8);
        buttonClose->setFlat(true);

        horizontalLayout->addWidget(buttonClose);


        gridLayout_2->addWidget(toolBarFrame, 0, 0, 1, 2);

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
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabScript), QApplication::translate("MainWindow", "Skripte", 0));
        NewCostume->setText(QApplication::translate("MainWindow", "Neues Kost\303\274m:", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabCostume), QApplication::translate("MainWindow", "Kost\303\274me", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabSound), QApplication::translate("MainWindow", "Kl\303\244nge", 0));
        buttonFullScreen->setText(QString());
        buttonScriptStart->setText(QString());
        buttonStopScript->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Figuren", 0));
        label->setText(QApplication::translate("MainWindow", "Neue Figur:", 0));
        pushButton_7->setText(QString());
        pushButton_6->setText(QString());
        pushButton_5->setText(QString());
        pushButton_8->setText(QString());
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
