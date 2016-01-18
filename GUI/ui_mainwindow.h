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
#include <costumeselect.h>
#include <dragelemlist.h>
#include <qsci/qsciscintilla.h>
#include <scene.h>
#include <scriptarea.h>
#include <soundselect.h>
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
        costumeFromLibrary = new QPushButton(frame_3);
        costumeFromLibrary->setObjectName(QStringLiteral("costumeFromLibrary"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(costumeFromLibrary->sizePolicy().hasHeightForWidth());
        costumeFromLibrary->setSizePolicy(sizePolicy3);
        costumeFromLibrary->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Assets/libraryOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        costumeFromLibrary->setIcon(icon);
        costumeFromLibrary->setFlat(true);

        horizontalLayout_6->addWidget(costumeFromLibrary);

        costumeFromDraw = new QPushButton(frame_3);
        costumeFromDraw->setObjectName(QStringLiteral("costumeFromDraw"));
        sizePolicy3.setHeightForWidth(costumeFromDraw->sizePolicy().hasHeightForWidth());
        costumeFromDraw->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Assets/paintbrushOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        costumeFromDraw->setIcon(icon1);
        costumeFromDraw->setFlat(true);

        horizontalLayout_6->addWidget(costumeFromDraw);

        costumeFromFile = new QPushButton(frame_3);
        costumeFromFile->setObjectName(QStringLiteral("costumeFromFile"));
        sizePolicy3.setHeightForWidth(costumeFromFile->sizePolicy().hasHeightForWidth());
        costumeFromFile->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Assets/importOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        costumeFromFile->setIcon(icon2);
        costumeFromFile->setFlat(true);

        horizontalLayout_6->addWidget(costumeFromFile);


        verticalLayout_3->addWidget(frame_3);

        costumeSelect = new CostumeSelect(frame);
        costumeSelect->setObjectName(QStringLiteral("costumeSelect"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(costumeSelect->sizePolicy().hasHeightForWidth());
        costumeSelect->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(costumeSelect);


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
        horizontalLayout_8 = new QHBoxLayout(tabSound);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame_4 = new QFrame(tabSound);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy5);
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
        sizePolicy3.setHeightForWidth(soundFromLibrary->sizePolicy().hasHeightForWidth());
        soundFromLibrary->setSizePolicy(sizePolicy3);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Assets/soundlibraryOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        soundFromLibrary->setIcon(icon3);
        soundFromLibrary->setFlat(true);

        horizontalLayout_9->addWidget(soundFromLibrary);

        soundFromRecord = new QPushButton(frame_6);
        soundFromRecord->setObjectName(QStringLiteral("soundFromRecord"));
        sizePolicy3.setHeightForWidth(soundFromRecord->sizePolicy().hasHeightForWidth());
        soundFromRecord->setSizePolicy(sizePolicy3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Assets/recordOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        soundFromRecord->setIcon(icon4);
        soundFromRecord->setFlat(true);

        horizontalLayout_9->addWidget(soundFromRecord);

        soundFromFile = new QPushButton(frame_6);
        soundFromFile->setObjectName(QStringLiteral("soundFromFile"));
        sizePolicy3.setHeightForWidth(soundFromFile->sizePolicy().hasHeightForWidth());
        soundFromFile->setSizePolicy(sizePolicy3);
        soundFromFile->setIcon(icon2);
        soundFromFile->setFlat(true);

        horizontalLayout_9->addWidget(soundFromFile);


        verticalLayout_4->addWidget(frame_6);

        soundSelect = new SoundSelect(frame_4);
        soundSelect->setObjectName(QStringLiteral("soundSelect"));
        sizePolicy4.setHeightForWidth(soundSelect->sizePolicy().hasHeightForWidth());
        soundSelect->setSizePolicy(sizePolicy4);

        verticalLayout_4->addWidget(soundSelect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_8->addWidget(frame_4);

        audioArea = new QFrame(tabSound);
        audioArea->setObjectName(QStringLiteral("audioArea"));
        sizePolicy2.setHeightForWidth(audioArea->sizePolicy().hasHeightForWidth());
        audioArea->setSizePolicy(sizePolicy2);
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
        sizePolicy2.setHeightForWidth(waveFormPlot->sizePolicy().hasHeightForWidth());
        waveFormPlot->setSizePolicy(sizePolicy2);

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
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Assets/fullScreenOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/Assets/fullScreenOff.png"), QSize(), QIcon::Normal, QIcon::On);
        buttonFullScreen->setIcon(icon5);
        buttonFullScreen->setFlat(true);

        horizontalLayout_2->addWidget(buttonFullScreen);

        lineEdit = new QLineEdit(upperSceneFrame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        buttonScriptStart = new QPushButton(upperSceneFrame);
        buttonScriptStart->setObjectName(QStringLiteral("buttonScriptStart"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Assets/greenFlagOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonScriptStart->setIcon(icon6);
        buttonScriptStart->setFlat(true);

        horizontalLayout_2->addWidget(buttonScriptStart);

        buttonStopScript = new QPushButton(upperSceneFrame);
        buttonStopScript->setObjectName(QStringLiteral("buttonStopScript"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../../scratch-flash/src/assets/UI/buttons/stopOn.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStopScript->setIcon(icon7);
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
        selectionBackground = new QWidget(selectionFrame);
        selectionBackground->setObjectName(QStringLiteral("selectionBackground"));
        sizePolicy5.setHeightForWidth(selectionBackground->sizePolicy().hasHeightForWidth());
        selectionBackground->setSizePolicy(sizePolicy5);
        selectionBackground->setMinimumSize(QSize(75, 0));

        gridLayout->addWidget(selectionBackground, 1, 0, 1, 1);

        upperSpriteFrame = new QFrame(selectionFrame);
        upperSpriteFrame->setObjectName(QStringLiteral("upperSpriteFrame"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(upperSpriteFrame->sizePolicy().hasHeightForWidth());
        upperSpriteFrame->setSizePolicy(sizePolicy6);
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
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Assets/landscapeOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon8);
        pushButton_8->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_8);


        gridLayout->addWidget(upperSpriteFrame, 0, 1, 1, 1);

        selectionPaddingFrame = new QFrame(selectionFrame);
        selectionPaddingFrame->setObjectName(QStringLiteral("selectionPaddingFrame"));
        sizePolicy6.setHeightForWidth(selectionPaddingFrame->sizePolicy().hasHeightForWidth());
        selectionPaddingFrame->setSizePolicy(sizePolicy6);
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
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(toolBarFrame->sizePolicy().hasHeightForWidth());
        toolBarFrame->setSizePolicy(sizePolicy7);
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
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(buttonFile->sizePolicy().hasHeightForWidth());
        buttonFile->setSizePolicy(sizePolicy8);
        buttonFile->setMinimumSize(QSize(0, 20));
        buttonFile->setStyleSheet(QLatin1String("QMenu\n"
"{\n"
"	background-color: #9c9ea2;\n"
"}"));
        buttonFile->setFlat(true);

        horizontalLayout->addWidget(buttonFile);

        buttonEdit = new QPushButton(toolBarFrame);
        buttonEdit->setObjectName(QStringLiteral("buttonEdit"));
        sizePolicy8.setHeightForWidth(buttonEdit->sizePolicy().hasHeightForWidth());
        buttonEdit->setSizePolicy(sizePolicy8);
        buttonEdit->setMinimumSize(QSize(0, 20));
        buttonEdit->setFlat(true);

        horizontalLayout->addWidget(buttonEdit);

        buttonHints = new QPushButton(toolBarFrame);
        buttonHints->setObjectName(QStringLiteral("buttonHints"));
        sizePolicy6.setHeightForWidth(buttonHints->sizePolicy().hasHeightForWidth());
        buttonHints->setSizePolicy(sizePolicy6);
        buttonHints->setMinimumSize(QSize(0, 20));
        buttonHints->setFlat(true);

        horizontalLayout->addWidget(buttonHints);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonMinimize = new QPushButton(toolBarFrame);
        buttonMinimize->setObjectName(QStringLiteral("buttonMinimize"));
        buttonMinimize->setMinimumSize(QSize(0, 20));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Assets/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMinimize->setIcon(icon9);
        buttonMinimize->setFlat(true);

        horizontalLayout->addWidget(buttonMinimize);

        buttonClose = new QPushButton(toolBarFrame);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setMinimumSize(QSize(0, 20));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Assets/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonClose->setIcon(icon10);
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
        centerAreaWidget->setTabText(centerAreaWidget->indexOf(tabCode), QApplication::translate("MainWindow", "Seite", 0));
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
