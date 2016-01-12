#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFont>
#include <QFontMetrics>
#include <QPainterPath>
#include <QDebug>

#include "audioengine.h"
#include "costume.h"
#include "dragelemcategory.h"
#include "commandde.h"
#include "hatde.h"
#include "sprite.h"
#include "wrapperde.h"
#include "predicatede.h"
#include "reporterde.h"
#include "Qsci/qscilexerpython.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    Sprite* figure = new Sprite(ui->scriptArea);
    Sprite* sprite = new Sprite(ui->scriptArea);
    ui->spriteSelect->addSprite(figure);
    ui->spriteSelect->addSprite(sprite);
    ui->scriptArea->setCurrentSprite(figure);
    _currentSprite = figure;

    _backgroundSprite = new Sprite();

    _audioEngine = new AudioEngine(this);
    _audioEngine->setCurrentSprite(figure);

    InitializeDragElem(":/blocks.xml");

    ui->categorySelect->setElemListWidget(ui->elementList);
    ui->categorySelect->setScriptAreaWidget(ui->scriptArea);

    connect(this, SIGNAL(newSound()), ui->soundSelect, SLOT(updateSoundList()));
    connect(this, SIGNAL(newCostume()), ui->costumeSelect, SLOT(updateCostumeList()));
    ui->soundSelect->changeCurrentSprite(figure);
    ui->costumeSelect->changeCurrentSprite(figure);

    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(10);
    QFontMetrics fm = QFontMetrics(font);
    ui->codeEditor->setFont(font);
    ui->codeEditor->setMarginsFont(font);
    ui->codeEditor->setMarginWidth(0, fm.width( "00000" ) + 5);
    ui->codeEditor->setMarginLineNumbers(0, true);
    ui->codeEditor->setFolding(QsciScintilla::BoxedTreeFoldStyle);
    ui->codeEditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    ui->codeEditor->setCaretLineVisible(true);
    ui->codeEditor->setCaretLineBackgroundColor(QColor("#ffe4e4"));
    ui->codeEditor->setMarginsBackgroundColor(QColor("#333333"));
    ui->codeEditor->setMarginsForegroundColor(QColor("#CCCCCC"));
    ui->codeEditor->setFoldMarginColors(QColor("#99CC66"), QColor("#333300"));

    QsciLexerPython lexer;
    lexer.setDefaultFont(font);
    ui->codeEditor->setLexer(&lexer);

    CodeGenerator Cgen= new CodeGenerator(this);
}

void MainWindow::InitializeDragElem(const QString& path)
{
    QFile styleSheet(path);
    styleSheet.open(QFile::ReadOnly);
    QString xml = QLatin1String(styleSheet.readAll());

    QXmlStreamReader xmlReader(xml);
    QXmlStreamAttributes attributes;

    DragableElement* lastElement;

    while(!xmlReader.atEnd())
    {
        if(xmlReader.readNext() == QXmlStreamReader::StartElement)
        {
            QString type = xmlReader.name().toString();
            if(type == "dragableelement")
            {
                attributes = xmlReader.attributes();
                DragElemCategory* category = GetCategoryByName(attributes.value("category").toString());
                if(attributes.value("type").toString() == "command")
                {
                    lastElement = new CommandDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "hat")
                {
                    lastElement = new HatDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "wrapper")
                {
                    lastElement = new WrapperDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "predicate")
                {
                    lastElement = new PredicateDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "reporter")
                {
                    lastElement = new ReporterDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                category->_elemList.push_back(lastElement);
            }
            else if(type == "parameter")
            {
                attributes = xmlReader.attributes();
                lastElement->_defaultValues.push_back(attributes.value("default").toString());
            }
            else if(type == "dragelemcategory")
            {
                attributes = xmlReader.attributes();
                DragElemCategory* category = new DragElemCategory(attributes.value("name").toString(), QColor(attributes.value("color").toString()), this);
                ui->categorySelect->_categoryList.push_back(category);
            }
        }
    }
    ui->categorySelect->show();
}

DragElemCategory* MainWindow::GetCategoryByName(const QString& name)
{
    for(CategoryList::iterator category = ui->categorySelect->_categoryList.begin(); category != ui->categorySelect->_categoryList.end(); category++)
    {
        if((*category)->_label.text() == name) return (*category);
    }
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_soundFromFile_clicked()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open WAV file"), dir, "*.wav");
    if (fileNames.count())
    {
        _audioEngine->loadFile(fileNames.front());
    }
    emit newSound();
}

void MainWindow::on_costumeFromFile_clicked()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open PNG file"), dir, "*.png");
    if (fileNames.count())
    {
        Costume* costume = new Costume(_currentSprite);
        costume->open(fileNames.front());
        _currentSprite->getCostumeVector()->push_back(costume);
    }
    emit newCostume();
}
