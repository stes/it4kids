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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <categoryselect.h>
#include <costumeselect.h>
#include <dragelemlist.h>
#include <Qsci/qsciscintilla.h>
#include <scene.h>
#include <scriptarea.h>
#include <soundselect.h>
#include <spriteselect.h>
#include <studentlist.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
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
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_13;
    SpriteSelect *spriteSelect;
    QSpacerItem *horizontalSpacer_3;
    QFrame *toolBarFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonFile;
    QPushButton *buttonEdit;
    QPushButton *buttonHints;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonMinimize;
    QPushButton *buttonClose;
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
    QPushButton *costumeFromLibrary;
    QPushButton *costumeFromDraw;
    QPushButton *costumeFromFile;
    CostumeSelect *costumeSelect;
    QFrame *frame_2;
    QWidget *tabSound;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *soundFromLibrary;
    QPushButton *soundFromRecord;
    QPushButton *soundFromFile;
    SoundSelect *soundSelect;
    QSpacerItem *verticalSpacer;
    QFrame *audioArea;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_3;
    QWidget *waveFormPlot;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_13;
    QWidget *tabCode;
    QVBoxLayout *verticalLayout_6;
    QsciScintilla *codeEditor;
    QWidget *tabTeacher;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_4;
    QPushButton *pushButton;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_5;
    QLabel *label_6;
    StudentList *studentList;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QComboBox *comboBox;
    QListWidget *listWidget;
    QListWidget *listAddDragElem;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButton_2;
    QPushButton *buttonAddDragElem;

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

        scene = new Scene(leftAreaFrame);
        scene->setObjectName(QStringLiteral("scene"));
        sizePolicy.setHeightForWidth(scene->sizePolicy().hasHeightForWidth());
        scene->setSizePolicy(sizePolicy);
        scene->setMinimumSize(QSize(482, 360));

        verticalLayout->addWidget(scene);

        selectionFrame = new QFrame(leftAreaFrame);
        selectionFrame->setObjectName(QStringLiteral("selectionFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectionFrame->sizePolicy().hasHeightForWidth());
        selectionFrame->setSizePolicy(sizePolicy1);
        selectionFrame->setMinimumSize(QSize(482, 0));
        selectionFrame->setFrameShape(QFrame::StyledPanel);
        selectionFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(selectionFrame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        selectionBackground = new QWidget(selectionFrame);
        selectionBackground->setObjectName(QStringLiteral("selectionBackground"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectionBackground->sizePolicy().hasHeightForWidth());
        selectionBackground->setSizePolicy(sizePolicy2);
        selectionBackground->setMinimumSize(QSize(75, 0));

        gridLayout->addWidget(selectionBackground, 1, 0, 1, 1);

        upperSpriteFrame = new QFrame(selectionFrame);
        upperSpriteFrame->setObjectName(QStringLiteral("upperSpriteFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(upperSpriteFrame->sizePolicy().hasHeightForWidth());
        upperSpriteFrame->setSizePolicy(sizePolicy3);
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
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Assets/libraryOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon3);
        pushButton_7->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(upperSpriteFrame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Assets/paintbrushOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(upperSpriteFrame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Assets/importOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);
        pushButton_5->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(upperSpriteFrame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Assets/landscapeOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_8);


        gridLayout->addWidget(upperSpriteFrame, 0, 1, 1, 1);

        selectionPaddingFrame = new QFrame(selectionFrame);
        selectionPaddingFrame->setObjectName(QStringLiteral("selectionPaddingFrame"));
        sizePolicy3.setHeightForWidth(selectionPaddingFrame->sizePolicy().hasHeightForWidth());
        selectionPaddingFrame->setSizePolicy(sizePolicy3);
        selectionPaddingFrame->setMinimumSize(QSize(0, 40));
        selectionPaddingFrame->setFrameShape(QFrame::StyledPanel);
        selectionPaddingFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(selectionPaddingFrame, 0, 0, 1, 1);

        frame_5 = new QFrame(selectionFrame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_5);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        spriteSelect = new SpriteSelect(frame_5);
        spriteSelect->setObjectName(QStringLiteral("spriteSelect"));

        horizontalLayout_13->addWidget(spriteSelect);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);


        gridLayout->addWidget(frame_5, 1, 1, 1, 1);


        verticalLayout->addWidget(selectionFrame);


        gridLayout_2->addWidget(leftAreaFrame, 1, 0, 1, 1);

        toolBarFrame = new QFrame(centralWidget);
        toolBarFrame->setObjectName(QStringLiteral("toolBarFrame"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(toolBarFrame->sizePolicy().hasHeightForWidth());
        toolBarFrame->setSizePolicy(sizePolicy4);
        toolBarFrame->setMinimumSize(QSize(0, 23));
        toolBarFrame->setStyleSheet(QLatin1String("QFrame#toolBarFrame\n"
"{\n"
"	background-color: #9c9ea2;\n"
"}\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(toolBarFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonFile = new QPushButton(toolBarFrame);
        buttonFile->setObjectName(QStringLiteral("buttonFile"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(buttonFile->sizePolicy().hasHeightForWidth());
        buttonFile->setSizePolicy(sizePolicy5);
        buttonFile->setMinimumSize(QSize(0, 20));
        buttonFile->setStyleSheet(QLatin1String("QMenu\n"
"{\n"
"	background-color: #9c9ea2;\n"
"}"));
        buttonFile->setFlat(true);

        horizontalLayout->addWidget(buttonFile);

        buttonEdit = new QPushButton(toolBarFrame);
        buttonEdit->setObjectName(QStringLiteral("buttonEdit"));
        sizePolicy5.setHeightForWidth(buttonEdit->sizePolicy().hasHeightForWidth());
        buttonEdit->setSizePolicy(sizePolicy5);
        buttonEdit->setMinimumSize(QSize(0, 20));
        buttonEdit->setFlat(true);

        horizontalLayout->addWidget(buttonEdit);

        buttonHints = new QPushButton(toolBarFrame);
        buttonHints->setObjectName(QStringLiteral("buttonHints"));
        sizePolicy3.setHeightForWidth(buttonHints->sizePolicy().hasHeightForWidth());
        buttonHints->setSizePolicy(sizePolicy3);
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
        sizePolicy1.setHeightForWidth(categorySelect->sizePolicy().hasHeightForWidth());
        categorySelect->setSizePolicy(sizePolicy1);
        categorySelect->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(categorySelect);

        elementList = new DragElemList(CategorySelectFrame);
        elementList->setObjectName(QStringLiteral("elementList"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(elementList->sizePolicy().hasHeightForWidth());
        elementList->setSizePolicy(sizePolicy6);
        elementList->setMinimumSize(QSize(200, 50));

        verticalLayout_2->addWidget(elementList);


        horizontalLayout_3->addWidget(CategorySelectFrame);

        scriptArea = new ScriptArea(tabScript);
        scriptArea->setObjectName(QStringLiteral("scriptArea"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(scriptArea->sizePolicy().hasHeightForWidth());
        scriptArea->setSizePolicy(sizePolicy7);
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
        costumeFromLibrary = new QPushButton(frame_3);
        costumeFromLibrary->setObjectName(QStringLiteral("costumeFromLibrary"));
        sizePolicy.setHeightForWidth(costumeFromLibrary->sizePolicy().hasHeightForWidth());
        costumeFromLibrary->setSizePolicy(sizePolicy);
        costumeFromLibrary->setStyleSheet(QStringLiteral(""));
        costumeFromLibrary->setIcon(icon3);
        costumeFromLibrary->setFlat(true);

        horizontalLayout_6->addWidget(costumeFromLibrary);

        costumeFromDraw = new QPushButton(frame_3);
        costumeFromDraw->setObjectName(QStringLiteral("costumeFromDraw"));
        sizePolicy.setHeightForWidth(costumeFromDraw->sizePolicy().hasHeightForWidth());
        costumeFromDraw->setSizePolicy(sizePolicy);
        costumeFromDraw->setIcon(icon4);
        costumeFromDraw->setFlat(true);

        horizontalLayout_6->addWidget(costumeFromDraw);

        costumeFromFile = new QPushButton(frame_3);
        costumeFromFile->setObjectName(QStringLiteral("costumeFromFile"));
        sizePolicy.setHeightForWidth(costumeFromFile->sizePolicy().hasHeightForWidth());
        costumeFromFile->setSizePolicy(sizePolicy);
        costumeFromFile->setIcon(icon5);
        costumeFromFile->setFlat(true);

        horizontalLayout_6->addWidget(costumeFromFile);


        verticalLayout_3->addWidget(frame_3);

        costumeSelect = new CostumeSelect(frame);
        costumeSelect->setObjectName(QStringLiteral("costumeSelect"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(costumeSelect->sizePolicy().hasHeightForWidth());
        costumeSelect->setSizePolicy(sizePolicy8);

        verticalLayout_3->addWidget(costumeSelect);


        horizontalLayout_5->addWidget(frame);

        frame_2 = new QFrame(tabCostume);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy7.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy7);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frame_2);

        centerAreaWidget->addTab(tabCostume, QString());
        tabSound = new QWidget();
        tabSound->setObjectName(QStringLiteral("tabSound"));
        horizontalLayout_8 = new QHBoxLayout(tabSound);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame_4 = new QFrame(tabSound);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font-weight: bold;\n"
"color: #5c5d5f;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_6);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        soundFromLibrary = new QPushButton(frame_6);
        soundFromLibrary->setObjectName(QStringLiteral("soundFromLibrary"));
        sizePolicy.setHeightForWidth(soundFromLibrary->sizePolicy().hasHeightForWidth());
        soundFromLibrary->setSizePolicy(sizePolicy);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Assets/soundlibraryOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        soundFromLibrary->setIcon(icon9);
        soundFromLibrary->setFlat(true);

        horizontalLayout_9->addWidget(soundFromLibrary);

        soundFromRecord = new QPushButton(frame_6);
        soundFromRecord->setObjectName(QStringLiteral("soundFromRecord"));
        sizePolicy.setHeightForWidth(soundFromRecord->sizePolicy().hasHeightForWidth());
        soundFromRecord->setSizePolicy(sizePolicy);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Assets/recordOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        soundFromRecord->setIcon(icon10);
        soundFromRecord->setFlat(true);

        horizontalLayout_9->addWidget(soundFromRecord);

        soundFromFile = new QPushButton(frame_6);
        soundFromFile->setObjectName(QStringLiteral("soundFromFile"));
        sizePolicy.setHeightForWidth(soundFromFile->sizePolicy().hasHeightForWidth());
        soundFromFile->setSizePolicy(sizePolicy);
        soundFromFile->setIcon(icon5);
        soundFromFile->setFlat(true);

        horizontalLayout_9->addWidget(soundFromFile);


        verticalLayout_4->addWidget(frame_6);

        soundSelect = new SoundSelect(frame_4);
        soundSelect->setObjectName(QStringLiteral("soundSelect"));
        sizePolicy8.setHeightForWidth(soundSelect->sizePolicy().hasHeightForWidth());
        soundSelect->setSizePolicy(sizePolicy8);

        verticalLayout_4->addWidget(soundSelect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_8->addWidget(frame_4);

        audioArea = new QFrame(tabSound);
        audioArea->setObjectName(QStringLiteral("audioArea"));
        sizePolicy7.setHeightForWidth(audioArea->sizePolicy().hasHeightForWidth());
        audioArea->setSizePolicy(sizePolicy7);
        audioArea->setStyleSheet(QLatin1String("QFrame#audioArea\n"
"{\n"
"	background-color: rgb(242, 242, 242);\n"
"}"));
        audioArea->setFrameShape(QFrame::StyledPanel);
        audioArea->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(audioArea);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame_7 = new QFrame(audioArea);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_7);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        lineEdit_2 = new QLineEdit(frame_7);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_10->addWidget(lineEdit_2);

        pushButton_10 = new QPushButton(frame_7);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_10->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(frame_7);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_10->addWidget(pushButton_9);


        verticalLayout_5->addWidget(frame_7);

        frame_8 = new QFrame(audioArea);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_8);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        widget_3 = new QWidget(frame_8);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout_11->addWidget(widget_3);

        waveFormPlot = new QWidget(frame_8);
        waveFormPlot->setObjectName(QStringLiteral("waveFormPlot"));
        sizePolicy7.setHeightForWidth(waveFormPlot->sizePolicy().hasHeightForWidth());
        waveFormPlot->setSizePolicy(sizePolicy7);

        horizontalLayout_11->addWidget(waveFormPlot);


        verticalLayout_5->addWidget(frame_8);

        frame_9 = new QFrame(audioArea);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_9);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pushButton_11 = new QPushButton(frame_9);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_12->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(frame_9);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        horizontalLayout_12->addWidget(pushButton_12);

        pushButton_14 = new QPushButton(frame_9);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        horizontalLayout_12->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(frame_9);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        horizontalLayout_12->addWidget(pushButton_15);

        pushButton_13 = new QPushButton(frame_9);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        horizontalLayout_12->addWidget(pushButton_13);


        verticalLayout_5->addWidget(frame_9);


        horizontalLayout_8->addWidget(audioArea);

        centerAreaWidget->addTab(tabSound, QString());
        tabCode = new QWidget();
        tabCode->setObjectName(QStringLiteral("tabCode"));
        verticalLayout_6 = new QVBoxLayout(tabCode);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        codeEditor = new QsciScintilla(tabCode);
        codeEditor->setObjectName(QStringLiteral("codeEditor"));

        verticalLayout_6->addWidget(codeEditor);

        centerAreaWidget->addTab(tabCode, QString());
        tabTeacher = new QWidget();
        tabTeacher->setObjectName(QStringLiteral("tabTeacher"));
        verticalLayout_7 = new QVBoxLayout(tabTeacher);
        verticalLayout_7->setSpacing(5);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame_10 = new QFrame(tabTeacher);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        sizePolicy3.setHeightForWidth(frame_10->sizePolicy().hasHeightForWidth());
        frame_10->setSizePolicy(sizePolicy3);
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_14 = new QHBoxLayout(frame_10);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_4 = new QLabel(frame_10);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_14->addWidget(label_4);

        pushButton = new QPushButton(frame_10);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_14->addWidget(pushButton);


        verticalLayout_7->addWidget(frame_10);

        frame_11 = new QFrame(tabTeacher);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        sizePolicy3.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy3);
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame_11);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_5 = new QLabel(frame_11);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_15->addWidget(label_5);

        label_6 = new QLabel(frame_11);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_15->addWidget(label_6);


        verticalLayout_7->addWidget(frame_11);

        studentList = new StudentList(tabTeacher);
        studentList->setObjectName(QStringLiteral("studentList"));
        sizePolicy5.setHeightForWidth(studentList->sizePolicy().hasHeightForWidth());
        studentList->setSizePolicy(sizePolicy5);
        studentList->setMinimumSize(QSize(0, 0));

        verticalLayout_7->addWidget(studentList);

        frame_12 = new QFrame(tabTeacher);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        sizePolicy8.setHeightForWidth(frame_12->sizePolicy().hasHeightForWidth());
        frame_12->setSizePolicy(sizePolicy8);
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_12);
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(frame_12);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(label_7);

        comboBox = new QComboBox(frame_12);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_16->addWidget(comboBox);

        listWidget = new QListWidget(frame_12);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_16->addWidget(listWidget);

        listAddDragElem = new QListWidget(frame_12);
        listAddDragElem->setObjectName(QStringLiteral("listAddDragElem"));
        listAddDragElem->setContextMenuPolicy(Qt::CustomContextMenu);
        listAddDragElem->setSelectionMode(QAbstractItemView::ExtendedSelection);

        horizontalLayout_16->addWidget(listAddDragElem);


        verticalLayout_7->addWidget(frame_12, 0, Qt::AlignTop);

        frame_13 = new QFrame(tabTeacher);
        frame_13->setObjectName(QStringLiteral("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_13);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButton_2 = new QPushButton(frame_13);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_17->addWidget(pushButton_2);

        buttonAddDragElem = new QPushButton(frame_13);
        buttonAddDragElem->setObjectName(QStringLiteral("buttonAddDragElem"));

        horizontalLayout_17->addWidget(buttonAddDragElem);


        verticalLayout_7->addWidget(frame_13);

        centerAreaWidget->addTab(tabTeacher, QString());

        gridLayout_2->addWidget(centerAreaWidget, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(buttonClose, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(buttonMinimize, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));
        QObject::connect(listAddDragElem, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(customContextMenuRequestedAddDragElem(QPoint)));

        centerAreaWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
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
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabScript), QApplication::translate("MainWindow", "Skripte", 0));
        NewCostume->setText(QApplication::translate("MainWindow", "Neues Kost\303\274m:", 0));
        costumeFromLibrary->setText(QString());
        costumeFromDraw->setText(QString());
        costumeFromFile->setText(QString());
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabCostume), QApplication::translate("MainWindow", "Kost\303\274me", 0));
        label_3->setText(QApplication::translate("MainWindow", "Neuer Klang:", 0));
        soundFromLibrary->setText(QString());
        soundFromRecord->setText(QString());
        soundFromFile->setText(QString());
        pushButton_10->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "PushButton", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabSound), QApplication::translate("MainWindow", "Kl\303\244nge", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabCode), QApplication::translate("MainWindow", "Code", 0));
        label_4->setText(QApplication::translate("MainWindow", "Angemeldet als:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Anmelden", 0));
        label_5->setText(QApplication::translate("MainWindow", "Kurs:", 0));
        label_6->setText(QApplication::translate("MainWindow", "0 von  0 Sch\303\274ler/innen online", 0));
        label_7->setText(QApplication::translate("MainWindow", "Stufe", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Anf\303\244nger", 0)
         << QApplication::translate("MainWindow", "Fortg,", 0)
         << QApplication::translate("MainWindow", "Profi", 0)
        );
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        buttonAddDragElem->setText(QApplication::translate("MainWindow", "PushButton", 0));
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabTeacher), QApplication::translate("MainWindow", "Kurs\303\274bersicht", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
